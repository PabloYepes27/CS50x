dol = -1
coins= 0
cents = 1
while (dol < 0):
    try:
        dol = float(input("Change owed: "))
    except ValueError:
        dol = -1
cents = round(m * 100)
if (cents >= 25):
    while (cents >= 25):
        cents -= 25
        coins+= 1
if (cents >= 10):
    while (cents >= 10):
        cents -= 10
        coins+= 1
if (cents >= 5):
    while (cents >= 5):
        cents -= 5
        coins+= 1
if (cents < 5):
    while (cents > 0):
        cents -= 1
        coins+= 1
print("{}".format(coins))