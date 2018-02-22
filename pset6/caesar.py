import sys
from cs50 import get_string

# handles command-line orders
if len(sys.argv) != 2 or int(sys.argv[1]) <= 0 :
    print("Usage: python caesar.py k")
    exit(1)

# get the key; the divide operator handles situations when k > 26
key = int(sys.argv[1]) % 26

plaintext = get_string("plaintext: ")

print("ciphertext: ", end="")

for c in plaintext:

# when a character is upper case
    if c.isalpha() and c.isupper():
        if (ord(c) + key) > 90:
            print(chr(ord(c) + key - 26), end="")
        else :
            print(chr(ord(c) + key), end="")

# when a character is lower case
    elif c.isalpha() and c.islower():

        if (ord(c) + key) > 122:
            print(chr(ord(c) + key - 26), end="")
        else:
            print(chr(ord(c) + key), end="")

# everything else
    else:
        print(c, end="")

print("")
exit(0)