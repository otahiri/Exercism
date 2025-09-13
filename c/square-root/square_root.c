#include "square_root.h"

int square_root(int n)
{
	int i = n;
	int j = (i + n / i) / 2;
	while (j < i)
	{
		i = j;
		j = (i + n / i) / 2;
	}
	return i;
}
