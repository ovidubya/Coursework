class Rectangle:

    # Variables are automatically initialled here

    def __init__(self, newX, newY, newWidth, newHeight):
        self.x = newX
        self.y = newY
        self.width = newWidth
        self.height = newHeight

    # This is a weird version of the toString method in Java.

    def __str__(self):
        return "Rectangle(" + str(self.x) + ", " + str(self.y) + ", " + str(self.width) + ", " + str(self.height) + ")"

    def right(self):
        return self.x + self.width

    def bottom(self):
        return self.y + self.height

    def size(self):
        return self.width, self.height

    def position(self):
        return self.x, self.y

    def area(self):
        return self.height * self.width

     # offset is 3 but user can choose what number they want. This expands rec if + num and shrinks if - num.
    def expand(self, offset = 3):
        a = self.x - offset
        b = self.y - offset
        c = self.width + (offset * 2)
        d = self.height + (offset * 2)
        r2 = Rectangle(a, b, c, d)
        return r2

    # for the points to be true, the user needs to enter within the range (x -> a) and (y -> b)
    def contains_point(self, i, j):
        a = self.x + self.width
        b = self.y + self.height
        if((i >= self.x) and (i <= a) and (j >= self.y) and (j <= b)):
            return True
        else:
            return False



