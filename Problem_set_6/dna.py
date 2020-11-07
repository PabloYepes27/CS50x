from sys import argv, exit
import csv


def max_substring(chain, substr):
    ans = [0] * len(chain)
    for i in range(len(chain) - len(substr), -1, -1):
        if chain[i: i + len(substr)] == substr:
            if i+ len(substr) > len(chain) - 1:
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(substr)]
    return max(ans)


def print_match(reader, actual):
    for line in reader:
        person = line[0]
        values = [int(val) for val in line[1:]]
        if values == actual:
            print(person)
            return
    print("no match")


def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    with open(argv[1]) as dna_db:
        db_reader = csv.reader(dna_db)
        all_sequences = next(db_reader)[1:]

        with open(argv[2]) as txt_file:
            chain = txt_file.read()
            actual = [max_substring(chain, seq) for seq in all_sequences]

    print_match(db_reader, actual)