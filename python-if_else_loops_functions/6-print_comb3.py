#!/usr/bin/python3
for i in range(0, 100, 1):
    e = int(i / 10)
    q = int(i % 10)
    if e == q:
        continue
    if e > q:
        continue
    if i == 89:
        print("{}{}".format(e, q))
        break
    print("{}{}, ".format(e, q), end="")
