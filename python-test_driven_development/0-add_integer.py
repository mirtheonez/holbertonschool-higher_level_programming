#!/usr/bin/python3
"""
Integers addition
function that adds 2 integers
add tow integer
"""


def add_integer(a, b=98):
    """
    add tow integer
    """
    if not isinstance(a, (int, float)):
        raise TypeError("a must be an integer")
    if not isinstance(b, (int, float)):
        raise TypeError("b must be an integer")
    return int(a) + int(b)