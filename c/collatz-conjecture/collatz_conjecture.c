#include "collatz_conjecture.h"

int steps(int start)
{
	int count = 0;
	if (start <= 0)
		return -1;
	while (start != 1)
	{
		if(start % 2 == 0)
			start /= 2;
		else
			start = (start * 3) + 1;
		count++;
	}
	return count;
}
