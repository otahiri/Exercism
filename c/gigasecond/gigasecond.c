#include "gigasecond.h"
#include <stdlib.h>  
#include <stdio.h>  

#define GIGA 1000000000
#define BUFFER_SIZE sizeof("YYYY-mm-dd HH:MM:SS")
void fill_arr(int date, int idx, char *arr)
{
	if (date == 0)
		return;
	fill_arr((date / 10),idx , arr);
	arr[idx++] = date % 10;
}
void gigasecond(time_t input, char *output, size_t size)
{
	int idx = 0;
	input += GIGA;
	struct tm *future = localtime(&input);
	fill_arr(future->tm_year + 1900, idx, output )
	idx += 4;
	output[idx] = '-';
	fill_arr(future->tm_month, idx, output )
		

}
