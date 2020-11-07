from sys import argv, exit
from cs50 import SQL
import csv


def main():
    # Check command line arguments
    if len(argv) != 2:
        exit("Usage: python roster.py House_name")
    house = argv[1]

    db = SQL("sqlite:///students.db")
    
    # Query database for all students sorted alphabetically by last name and then first name
    table = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", house)
    for row in table:
        if row['middle'] == None:
            name = "{} {}".format(row['first'], row['last'])
        else:
            name = "{} {} {}".format(row['first'], row['middle'], row['last'])
        
        # Print out each student's full name and birth year
        print(name, ", born ", row['birth'], sep="")


if __name__ == "__main__":
    main()