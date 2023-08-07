#!/usr/bin/python3
"""Define a function"""


def append_write(filename="", text=""):
    """Append a string to the end of a text file"""

    with open(filename, "a", encoding="utf-8") as file:
        file.write(text)

    return len(text)
