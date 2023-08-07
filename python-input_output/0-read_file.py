#!/usr/bin/python3
"""Define function"""


def read_file(filename=""):
    """Read and print data"""

    with open(filename, "r", encoding="utf-8") as file:
        for content in file:
            print(content, end="")