#!/usr/bin/python3
"""Create an empty class named BaseGeometry."""


class BaseGeometry:
    """define the fields and methods here"""

    def area(self):
        """define the area methode"""

        raise Exception("area() is not implemented")

    def integer_validator(self, name, value):
        """integer valudator method"""

        if type(value) is not int:
            raise TypeError("{} must be an integer".format(name))
        if value <= 0:
            raise ValueError("{} must be greater than 0".format(name))
