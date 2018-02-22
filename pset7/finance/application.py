from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app=Flask(__name__)


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"]="no-cache, no-store, must-revalidate"
    response.headers["Expires"]=0
    response.headers["Pragma"]="no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"]=usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"]=mkdtemp()
app.config["SESSION_PERMANENT"]=False
app.config["SESSION_TYPE"]="filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db=SQL("sqlite:///finance.db")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    # get all stocks the user is holding
    portfolio=db.execute("SELECT * FROM portfolio WHERE id=:id", id=session["user_id"])

    port_value=0

    # calculate the portfolio's value at current price
    for each_stock in portfolio:
        symbol=each_stock["symbol"]
        # fetch stock information
        stock=lookup(symbol)
        shares=each_stock["shares"]
        amount=each_stock["amount"]
        # the stock's current value
        current_value=stock["price"] * shares
        # add back to the portfolio's value
        port_value=port_value + current_value
        if amount != current_value:
            # update the portfolio table
            db.execute("UPDATE portfolio SET price=:price, amount=:amount WHERE id=:id AND symbol=:symbol",
                        price=stock["price"], amount=current_value, id=session["user_id"], symbol=symbol)

    # get current cash level
    current_cash=db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])
    # cash + stock value
    port_value=port_value + current_cash[0]["cash"]

    # print out to index.html
    update=db.execute(
        "SELECT symbol, shares, amount FROM portfolio WHERE id=:id", id=session["user_id"])
    return render_template("index.html", stocks=update, cash=current_cash[0]["cash"], total=port_value)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        stock=lookup(request.form.get("symbol"))

        # check valid inputs
        if not stock:
            return apology("The symbol is invalid!")

        sharecount=int(request.form.get("shares"))

        if not isinstance(sharecount, int) or sharecount < 0:
            return apology("Shares must be a positive integer!")

        # use session id to get the user's cash balance
        cash=db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])
        # calculate investment amount
        investment=sharecount * stock['price']
        # see if user has enough cash
        if cash[0]["cash"] < investment:
            return apology("Insufficient balance!")

        # write the transactions log
        db.execute("INSERT INTO transactions (id, symbol, shares, price, total) VALUES(:id, :symbol, :shares, :price, :total)",
                    id=session["user_id"], symbol=stock["symbol"], shares=sharecount, price=stock["price"], total=investment)
        # update cash balance
        db.execute("UPDATE users SET cash=cash - :investment WHERE id=:id",
                    id=session["user_id"], investment=investment)


        # see if user owns the stock already
        owned=db.execute("SELECT amount FROM portfolio WHERE id=:id AND symbol=:symbol",
                        id=session["user_id"], symbol=stock["symbol"])

        if not owned:
            # insert a new entry in the portfolio table
            db.execute("INSERT INTO portfolio (id, symbol, shares, amount, price) VALUES(:id, :symbol, :shares, :amount, :price)",
                        id=session["user_id"], symbol=stock["symbol"], shares=sharecount, amount=investment, price=stock["price"])

        else:
            # update investment value and share number
            db.execute("UPDATE portfolio SET amount=amount + :investment WHERE id=:id",
                        id=session["user_id"], investment=investment)
            db.execute("UPDATE portfolio SET shares=shares + :sharecount WHERE id=:id",
                        id=session["user_id"], sharecount=sharecount)
            # calculate new average stock price
            price_update=db.execute("SELECT shares, amount FROM portfolio WHERE id=:id AND symbol=:symbol",
                        id=session["user_id"], symbol=stock["symbol"])
            new_price=price_update[0]["amount"] / price_update[0]["shares"]
            # write new price
            db.execute("UPDATE portfolio SET price=:price WHERE id=:id", id=session["user_id"], price=new_price)

        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    record=db.execute("SELECT * FROM transactions WHERE id=:id", id=session["user_id"])

    return render_template("history.html", stocks=record)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows=db.execute("SELECT * FROM users WHERE username=:username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"]=rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":
        stock=lookup(request.form.get("symbol"))

        if not stock:
            return apology("The symbol is invalid!")

        else:
            return render_template("info.html", stock=stock)

    else:
        return render_template("quote.html")

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # make sure that user entered all three fields
        if not request.form.get("username"):
            return apology("Please provide a username!")

        elif not request.form.get("password"):
            return apology("Please provide a password!")

        elif not request.form.get("confirm"):
            return apology("Please enter the password again!")

        # make sure the password and confirmation match
        if request.form.get("password") != request.form.get("confirm"):
            return apology("Passwords must match!")

        # get the hash value based on user's password
        hash=generate_password_hash(request.form.get("password"))

        # insert username and hashvalue into the users table
        result=db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)",
                            username=request.form.get("username"), hash=hash)
        # check if the username is unique
        if not result:
            return apology("Username already exists!")

        # get the user_id and store it in the session
        user_id=db.execute("SELECT id FROM users WHERE username IS :username", username=request.form.get("username"))

        session['user_id']=user_id[0]['id']

        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():

    """Buy shares of stock"""
    if request.method == "POST":
        stock=lookup(request.form.get("symbol"))

        # check valid inputs
        if not stock:
            return apology("The symbol is invalid!")

        sharecount=int(request.form.get("shares"))

        if not isinstance(sharecount, int) or sharecount < 0:
            return apology("Shares must be a positive integer!")

        # do you own this stock?
        port=db.execute("SELECT * FROM portfolio WHERE id=:id AND symbol=:symbol", id=session["user_id"], symbol=stock["symbol"])
        if not port:
            return apology("You don't own this stock!")
        elif port[0]["shares"] < sharecount:
            return apology("You don't have enough shares!")

        divestment=sharecount * stock["price"]

        # write the transactions log
        db.execute("INSERT INTO transactions (id, symbol, shares, price, total) VALUES(:id, :symbol, :shares, :price, :total)",
                    id=session["user_id"], symbol=stock["symbol"], shares=- sharecount, price=stock["price"], total=divestment)
        # update cash balance
        db.execute("UPDATE users SET cash=cash + :divestment WHERE id=:id", id=session["user_id"], divestment=divestment)

        # update divestment value and share number
        db.execute("UPDATE portfolio SET amount=amount - :divestment WHERE id=:id", id=session["user_id"], divestment=divestment)
        db.execute("UPDATE portfolio SET shares=shares - :sharecount WHERE id=:id", id=session["user_id"], sharecount=sharecount)

        # calculate new average stock price
        price_update=db.execute("SELECT shares, amount FROM portfolio WHERE id=:id AND symbol=:symbol", id=session["user_id"], symbol=stock["symbol"])

        # check if the remaining sharecount is 0
        if price_update[0]["shares"] != 0:
            # if not, update the new price
            new_price=price_update[0]["amount"] / price_update[0]["shares"]
            # write new price
            db.execute("UPDATE portfolio SET price=:price WHERE id=:id", id=session["user_id"], price=new_price)
        else:
            # remove this record
            db.execute("DELETE FROM portfolio WHERE id=:id AND symbol=:symbol", id=session["user_id"], symbol=stock["symbol"])

        return redirect("/")

    else:
        return render_template("sell.html")


def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
