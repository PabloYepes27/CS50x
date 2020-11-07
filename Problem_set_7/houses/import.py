from sys import argv, exit
# from cs50 import SQL
import csv


def main():
    # Check command line arguments
    if len(argv) != 2:
        exit("Usage: python import.py characters.csv")

    # Open the csv file
    # db = SQL("sqlite:///students.db")
    with open(argv[1]) as csv_db:
        db_reader = csv.reader(csv_db)
        # db_reader = csv.DictReader(csv_db)
        # str_list = next(db_reader)
        for row in db_reader:
            # For each row , parse the name
            name_split = row[0].split(" ")
            if len(name_split) == 1:
                continue
            else:
                name, middle, last = name_split[0], name_split[1] if len(name_split) == 3 else None, name_split[-1]
            # elif len(name_split) == 2:
            #     name = name_split[0]
            #     middle = None
            #     last = name_split[1]
            # else:
            #     name = name_split[0]
            #     middle = name_split[1]
            #     last = name_split[2]
            # Insert each student into students table of student.db
            # db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", name, middle, last, row[1],  row[2])

if __name__ == "__main__":
    main()