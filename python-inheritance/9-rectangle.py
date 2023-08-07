#!/usr/bin/python3
"""Create a class BaseGeometry"""
BaseGeometry = __import__('7-base_geometry').BaseGeometry


class Rectangle(BaseGeometry):
    """A class representing a Rectangle"""

    def __init__(self, width, height):
        """Initializes a rectangle instance"""

        self.integer_validator("width", width)
        self.__width = width
        self.integer_validator("height", height)
        self.__height = height

    def area(self):
        """Calculates the area of a rectangle"""

        return self.__width * self.__height

    def __str__(self):
        """Get the string representation of the rectangle"""

        return "[Rectangle] {}/{}".format(self.__width, self.__height)
