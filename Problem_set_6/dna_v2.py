#!/usr/bin/python3
import csv
from sys import argv, exit

def function(chain, seq):
    """create and empty list set by 0"""
    str_count = [0] * len(chain)
    """
    len(chain) = len('TATCTATCTATCTATCTATCA') = 21
    len(seq) = len('TATC') = 4
    from 17 to -1 decrease in 1
    """
    for i in range(len(chain) - len(seq), -1, -1):
        """
        chain[11: 11 + 4] = 'TATC'
        seq = 'TATC'
        """
        if chain[i: i + len(seq)] == seq:
            """
            i + len(seq) = 15
            len(chain) - 1 = 20
            """
            if i + len(seq) > len(chain) - 1:
                str_count[i] = 1
            else:
                str_count[i] = 1 + str_count[i + len(seq)]
    """
    return a list with the max number of each STR's consecutivly
    [22, 33, 43, 12, 26, 18, 47, 41]
    """
    return max(str_count)

def main():
    if len(argv) != 3:
        exit("Usage: python dna.py data.csv sequence.txt")


    with open(argv[1]) as dna_db:
        db_reader = csv.reader(dna_db)
        """we create a list with all the STR names"""
        str_list = next(db_reader)[1:]

        with open(argv[2]) as file:
            chain = file.read()
            """
            chain = 'TATCTATCTATCTATCTATCA'
            str_name = each name of the str_list ejm= AGATC,AATG,TATC
            actual_list = list with the max str's
            """
            actual_list = [function(chain, str_name) for str_name in str_list]

        for line in db_reader:
            name = line[0]
            values = [int(val) for val in line[1:]]
            """if the actual list match with some candidate then print his name"""
            if values == actual_list:
                print(name)
                return
        print("no match")

if __name__ == "__main__":
    main()