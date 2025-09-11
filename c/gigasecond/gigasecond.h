#ifndef GIGASECOND_H
#define GIGASECOND_H

#include <time.h>

void gigasecond(time_t input, char *output, size_t size);
int fill_arr(int date, int idx, char *arr, int is_plus_ten);

#endif
