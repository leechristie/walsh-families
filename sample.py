from sys import argv
from random import randint

k = int(argv[1])
n = 545836
indices = set()
while len(indices) < k:
    indices.add(randint(0, n-1))

index = 0
with open("sample" + str(k) + ".txt", "w") as outfile:
    with open("families.txt") as infile:
        for line in infile:
            if index in indices:
                print(line.strip(), file=outfile, end="\n", flush=True)
            index += 1
print("wrote: sample" + str(k) + ".txt")
