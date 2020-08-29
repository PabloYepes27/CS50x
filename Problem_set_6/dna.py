#!/usr/bin/python3
import csv
from sys import argv


if __name__ == "__main__":
    if len(argv) is not 3:
        exit("Usage: python dna.py data.csv sequence.txt")

    str_list = []

    with open(argv[1], newline='') as dna_db:
        db_reader = csv.DictReader(dna_db)
        for row in db_reader:
            keys = dict(row).keys()
            for i in keys:
                if i not in str_list:
                    str_list.append(i)

    str_dict = {}
    str_count = []
    aux_count = 0

    with open(argv[2]) as file:
        chain = file.read()
        for i in range(len(chain)):
            str_count.append(0)

    for let in range(len(chain)):
        for elem in str_list:
            str_aux = chain[let:let + len(elem)]
            jump = let
            while (str_aux == elem):
                str_count[let] += 1
                jump += len(elem)
                str_aux = chain[jump: jump + len(elem)]
            if type(str_dict.get(elem)) is int:
                aux_count = str_dict.get(elem)
            if max(str_count) is not 0 and max(str_count) > aux_count:
                str_dict[elem] = max(str_count)
            str_count[let] = 0
            aux_count = 0

    find = 0

    with open(argv[1], newline='') as dna_db:
        db_reader = csv.DictReader(dna_db)
        for row in db_reader:
            for key_row in row.keys():
                for key_str in str_dict.keys():
                    if key_row == key_str:
                        if int(row[key_row]) == str_dict[key_str]:
                            find += 1
            if find == len(str_list) - 1:
                print(row["name"], sep="")
                break
            find = 0
    if find is 0:
        print("No match")
