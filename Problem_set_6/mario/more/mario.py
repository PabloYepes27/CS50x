#!/usr/bin/python3
n = 0
i = 0
while (n < 1 or n > 8):
    try:
        n = int(input("Height: "))
    except ValueError:
        n = 0
for i in range(1, n + 1):
    print(" " * (n - i), end="")
    print("#" * i, end="  ")
    print("#" * i)