#include "darts.h"

int score(coordinate_t landing_position)
{
	float sqrt_x = landing_position.x * landing_position.x;
	float sqrt_y = landing_position.y * landing_position.y;

	if (sqrt_x + sqrt_y >= 0 && sqrt_x + sqrt_y <= 1)
		return 10;
	if (sqrt_x + sqrt_y > 1 && sqrt_x + sqrt_y <= 25)
		return 5;
	if (sqrt_x + sqrt_y > 25 && sqrt_x + sqrt_y <= 100)
		return 1;
	return 0;
}
