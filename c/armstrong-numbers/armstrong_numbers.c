#include "armstrong_numbers.h"
#include <math.h>
#include <stdio.h>


bool is_armstrong_number(int candidate)
{
	int digit[33];
	int idx = 0;
	int pwer;
	int res = 0;
	int tmp = candidate;
	for (;tmp > 0; tmp /= 10)
		digit[idx++] = tmp % 10;	
	pwer = idx;
	idx = 0;
	for (;idx < pwer; idx++)
		res += (int)pow(digit[idx],pwer);
	return (res == candidate);
}
