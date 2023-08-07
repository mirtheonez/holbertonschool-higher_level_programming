#!/usr/bin/python3
"""Create a class BaseGeometry"""
BaseGeometry = __import__('7-base_geometry').BaseGeometry


class Rectangle(BaseGeometry):

    """A class representing a rectangle"""

    def __init__(self, width, height):
        """Initialize a rectangle instance"""

        self.__width = self.integer_validator("width", width)
        self.__height = self.integer_validator("height", height)
