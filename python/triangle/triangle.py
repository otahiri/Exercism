def equilateral(sides):
    for i in range(3):
        if sides[i] == 0:
            return False
    return sides[0] == sides[1] == sides[2]


def isosceles(sides):
    a, b, c = sorted(sides)
    if (a + b < c):
        return False
    return a == b or a == c or b == c


def scalene(sides):
    a, b, c = sorted(sides)
    if (a + b < c):
        return False
    return sides[0] != sides[1] != sides[2] != sides[0]
