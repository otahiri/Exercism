#include "perfect_numbers.h"

int classify_number(int num)
{
	int sum = 0;
	if (num <= 0)
		return ERROR;
	for (int i = 1; i < num; i++)
	{
		if ( num % i == 0)
			sum += i;
	}
	if (sum > num)
		return ABUNDANT_NUMBER; 
	if (sum < num)
		return DEFICIENT_NUMBER;
	if (sum == num)
		return PERFECT_NUMBER;
	return ERROR;
}
