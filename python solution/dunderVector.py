



class Vector:

    def __init__(self, x, y):
        self.x_component = x
        self.y_component = y

    def addVectors(self, other):

        if not isinstance(other, Vector):
            raise TypeError("Can only add Vector to Vector")
        
        x = self.x_component + other.x_component
        y = self.y_component + other.y_component

        return Vector(x , y)

    def __add__(self, other):
        return self.addVectors(other)

    def subtractVectors(self, other):

        if not isinstance(other, Vector):
            raise TypeError("Can only add Vector to Vector")

        x = self.x_component - other.x_component
        y = self.y_component - other.y_component

        return Vector(x, y)

    def __sub__(self, other):
        return self.subtractVectors(other)

    def __str__(self):
        return "< " + self.x_component + " ," + self.y_component  + " >"

    def checkEquality(self, other):

        if not isinstance(other, Vector):
            raise TypeError("Can only add Vector to Vector")

        if (self.x_component == other.x_component) and (self.y_component == other.y_component):
            return True

        else:
            return False

    def __eq__(self, other):
        return self.checkEquality(other)
          



    