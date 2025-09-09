#include "binary_search.h"
#include <stdlib.h>

const int *binary_search(int value, const int *arr, size_t length)
{
	int upper = length - 1;
	int bottom = 0;
	int mid;
	while (upper >= bottom)
	{
		mid = bottom + (upper - bottom) / 2;
		if (value > arr[mid])
			bottom = mid + 1;
		if (value < arr[mid])
			upper = mid - 1;
		if (value == arr[mid])
			return &arr[mid];
	}	
	return NULL;
}
