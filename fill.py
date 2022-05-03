from sys import argv
from random import randint

if __name__ == "__main__":
    n = int(argv[1])
    with open("list.txt", "w+") as f:
        for _ in range(n):
            f.write(str(randint(-100000, 100000)) + " ")
