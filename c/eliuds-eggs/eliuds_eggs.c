#include "eliuds_eggs.h"

int egg_count(int num)
{
	char bin[32];
	int i = 0;
	int count = 0;
	while (num > 0)
	{
		bin[i] = (num % 2) + '0';
		num /= 2;
		i++;
	}
	bin[i--] = '\0';
	while (i >= 0)
	{
		if (bin[i] == '1')
			count++;

		i--;
	}
	return  count;
}
