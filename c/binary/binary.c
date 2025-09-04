#include "binary.h"

int convert(const char *input)
{
	int i = 0;
	int num = 0;
	while (input[i])
	{
		if (input[i] != '1' && input[i] != '0')
			return INVALID;
		i++;
	}
	i = 0;
	while (input[i])
	{
		num *= 2;
		num += (input[i] - '0');
		i++;
	}
	return num;
}
