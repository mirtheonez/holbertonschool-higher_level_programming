#!/usr/bin/python3
"""Define a function"""


def inherits_from(obj, a_class):
    """
    check if obj is an instance of a class that
    inherited from a_class
    """

    return issubclass(type(obj), a_class) and type(obj) != a_class
