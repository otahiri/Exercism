#include "sum_of_multiples.h"
#include <stdlib.h>

int is_similar(unsigned int *arr, unsigned int num, int size)
{
	for (int i = 0; i < size; i++)
	{
		if(arr[i] == num)
			return 1;
	}
	return 0;
}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit)
{
	unsigned int *multi = malloc(sizeof(int) * (limit * number_of_factors));
	unsigned int sum = 0;
	int i = 0;
	for (size_t tmp_idx = number_of_factors;tmp_idx >= 1; tmp_idx--)
	
	{
		for (unsigned int num = 0; num < limit; num++)
		{
			if (factors[tmp_idx - 1] && !(num % factors[tmp_idx - 1]) && !is_similar(multi, num, i))
			{
				multi[i] = num;
				sum += multi[i];
				i++;
			}

		}
	}
	return sum;
}
