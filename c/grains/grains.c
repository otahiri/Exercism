#include "grains.h"

uint64_t square(uint8_t index)
{
	uint64_t sum = 1;
	while (index > 1)
	{
		sum *= 2;
		index--;
	}
	if (index == 0)
		return 0;
	return sum;
}

uint64_t total(void)
{
	int i = 0;
	uint64_t sum = 0;
	while (i < 64)
	{
		if ( i == 0)
		{
			sum = 1;
			i++;
			continue;
		}
		sum *= 2;
		i++;
	}
	return sum;
}
