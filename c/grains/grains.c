#include "grains.h"

uint64_t square(uint8_t index)
{
	uint64_t num = 1;
	if (index <= 0 || index > 64)
		return 0;
	while (index > 1)
	{
		num *= 2;
		index--;
	}
	return num;
}
uint64_t total(void)
{
	uint64_t num = 1;
	int power = 64;
	while (power > 1)
	{
		num *= 2;
		num += 1;
		power--;
	}
	return (num);
}


