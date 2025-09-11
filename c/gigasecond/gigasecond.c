#include "gigasecond.h"
#include <stdlib.h>

#define GIGA 1000000000
int fill_arr(int date, int idx, char *arr, int is_plus_ten)
{
	if (is_plus_ten && date < 10)
	{
		arr[idx++] = '0';
		arr[idx++] = (date % 10) + '0';
		return idx;
	}
	if (date >= 10)
		idx = fill_arr((date / 10),idx , arr, 0);
	arr[idx++] = (date % 10) + '0';
	return idx;
}
void gigasecond(time_t input, char *output, size_t size)
{
	int idx = size;
	idx = 0;
	input += GIGA;
	struct tm *future = gmtime(&input);
	idx = fill_arr(future->tm_year + 1900, idx, output, 1);
	output[idx++] = '-';
	idx = fill_arr(future->tm_mon + 1, idx, output, 1);
	output[idx++] = '-';
	idx = fill_arr(future->tm_mday, idx, output, 1);
	output[idx++] = ' ';
	idx = fill_arr(future->tm_hour, idx, output, 1);
	output[idx++] = ':';
	idx = fill_arr(future->tm_min, idx, output, 1);
	output[idx++] = ':';
	idx = fill_arr(future->tm_sec, idx, output, 1);
	output[idx] = '\0';
}
