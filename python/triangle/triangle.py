def comp(sides):
    count = 0
    for x in sides:
        for y in sides:
            if x == y:
                count += 1
    return count - 3

def equilateral(sides):
    return comp(sides) == 3

def isosceles(sides):
    return comp(sides) == 2


def scalene(sides):
    return comp(sides) == 0
