#include "clock.h"


int clock_to_mins(clock_t clock)
{
	int min = 0;
	int hour = 0;
	hour = ((clock.text[0] - '0') * 10) + (clock.text[1] - '0');
	min = ((clock.text[3] - '0') * 10) + (clock.text[4] - '0');
	return (min + (hour * 60));
}

clock_t clock_create(int hour, int minute)
{
	clock_t time;
	int total = hour * 60 + minute;
	total = ((total % 1440) + 1440) % 1440;
	int mins = total % 60;
	int hours = total / 60;
	time.text[1] = (hours % 10) + '0';
	time.text[0] = (hours / 10) + '0';
	time.text[2] = ':';
	time.text[4] = (mins % 10) + '0';
	time.text[3] = (mins / 10) + '0';
	time.text[5] = '\0';
	return time;
}

clock_t clock_add(clock_t clock, int minute_add)
{
	int mins = clock_to_mins(clock);
	mins += minute_add;
	return clock_create(mins / 60, mins % 60);
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
	int mins = clock_to_mins(clock);
	mins -= minute_subtract;
	return clock_create(mins / 60, mins % 60);
}

bool clock_is_equal(clock_t a, clock_t b)
{
	return ((clock_to_mins(a)) == (clock_to_mins(b)));
}
