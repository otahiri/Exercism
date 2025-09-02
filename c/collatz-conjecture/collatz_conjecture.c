#include "collatz_conjecture.h"

int steps(int start)
{
	int i = 0;
	if (start <= 0)
		return ERROR_VALUE;
	while (start != 1)
	{
		if (start % 2 == 0)
			start /= 2;
		else
			start = (start * 3) + 1;
		i++;
	}
	return i;
}
