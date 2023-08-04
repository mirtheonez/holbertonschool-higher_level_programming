#!/usr/bin/python3
"""Class Definition"""


class Square:
    """A class represening a square.

    Attributes:
        __size (int): The size of the square.

    Methods:
        __init__(self, __size): Initializes a Square object.
    """

    def __init__(self, _size):
        """Initialize a Square object with the given size.

        Args:
            __size (int): The size of the square.
        """
        self.__size = _size
