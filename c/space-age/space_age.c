#include "space_age.h"

float age(planet_t planet, int64_t seconds)
{
	if (planet > 7 || planet < 0)
		return -1;
	float rando[8] = {0.2408467, 0.61519726, 1.0, 1.8808158, 11.862615, 29.447498, 84.016846, 164.79132};
	float years = 0;
	years = seconds / 60;
	years /= 60;
	years /= 24;
	years /= (365.2425 * rando[planet]);
	return years;
}
		
