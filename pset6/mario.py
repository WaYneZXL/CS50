from cs50 import get_int

# prompt for a positive number
while True:
    height = get_int("Height: ")
    if height >= 0 and height < 24:
        break

for i in range(0, height):
    spacecount = height - i - 1
    hashcount = height + 1 - spacecount
    print(" " * spacecount, end="")
    print("#" * hashcount)