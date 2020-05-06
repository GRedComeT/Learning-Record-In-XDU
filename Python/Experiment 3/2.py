class Geometric():
    pi = 3.1415926
    def __init__(self):
        self.area=0
        self.perimeter=0
        self.Area()
        self.Perimeter()
        self.printGeometric()

    def Area(self):
        pass

    def Perimeter(self):
        pass
    
    #print the value of Geometric
    def printGeometric(self):
        print("The Area is {}, the Perimeter is {}".format(self.area, self.perimeter))
    


class Triangle(Geometric):
    def __init__(self, a, b, c):
        ''' need each edge's length(a, b, c)'''
        self.a = int(a)
        self.b = int(b)
        self.c = int(c)
        super().__init__()
    
    def Area(self):
        a = self.a
        b = self.b
        c = self.c
        p = (a+b+c) / 2
        self.area = (p*(p-a)*(p-b)*(p-c))**0.5

    def Perimeter(self):
        self.perimeter = self.a + self.b + self.c

Angle = Triangle(3, 4, 5)

print(Angle.perimeter)
print(Angle.area)

class Rectangle(Geometric):
    ''' need the length and width'''
    def __init__(self, length, width):
        self.length = length
        self.width = width
        super().__init__()
        

    def Area(self):
        self.area = self.length * self.width

    def Perimeter(self):
        self.perimeter = 2 * (self.length + self.width)

Res = Rectangle(2, 2)
print(Res.area)
print(Res.perimeter)

class CircleAround(Geometric):
    '''need the "r"'''
    def __init__(self, r):
        self.r = r
        super().__init__()

    def Area(self):
        self.area = self.pi * self.r**2

    def Perimeter(self):
        self.perimeter = self.pi * 2 * self.r

r1 = CircleAround(4)
print(r1.area)
