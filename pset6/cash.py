from cs50 import get_float

# prompt for a positive number
while True:
    amount = get_float("Change owed: ")
    if amount >= 0:
        break

# get number of cents
cents = round(amount * 100)

# when total cents are more than 25, 10, 5, etc.
if cents >= 25:
    quarter = cents // 25
    remainder1 = cents % 25
    dime = remainder1 // 10
    remainder2 = remainder1 % 10
    nikel = remainder2 // 5
    cent = remainder2 % 5
    total = quarter + dime + nikel + cent

elif cents < 25 and cents >=10:
    dime = cents // 10
    remainder = cents % 10
    nikel = remainder // 5
    cent = remainder % 5
    total = dime + nikel + cent

elif cents < 10 and cents >= 5:
    total = 1 + (cents - 5)

else:
    total = cents

print(total)

