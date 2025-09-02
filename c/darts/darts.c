#include "darts.h"


int score(coordinate_t landing_position)
{
	float x = landing_position.x *	landing_position.x;
	float y = landing_position.y *	landing_position.y;
	if ((x + y) >= 0 && (x + y) <= 1)
		return 10;
	if ((x + y) > 1 && (x + y) <= 25)
		return 5;
	if ((x + y) > 25 && (x + y) <= 100)
		return 1;
	else 
		return 0;

}
