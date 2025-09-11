#include "triangle.h"

bool is_valid(triangle_t sides)
{
	return (sides.a + sides.b > sides.c && sides.b + sides.c > sides.a && sides.a + sides.c > sides.b);
}

bool is_equilateral(triangle_t sides)
{
	return (is_valid(sides) && sides.a == sides.b && sides.b == sides.c);
}
bool is_isosceles(triangle_t sides)
{
	return (is_valid(sides) && (sides.a == sides.b || sides.b == sides.c || sides.a == sides.c));
}
bool is_scalene(triangle_t sides)
{
	return (is_valid(sides) && sides.a != sides.b && sides.b != sides.c && sides.a != sides.c);
}
