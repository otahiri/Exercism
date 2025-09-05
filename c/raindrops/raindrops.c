#include "raindrops.h"
#include <string.h>
#include <stdio.h>

void convert(char result[], int drops)
{
	char *answers[3] = {"Pling", "Plang", "Plong"};
	int idx;
	int did = 0;;

	if (drops % 3 == 0)
	{
		idx = 0;
		strcat(result, answers[idx]);
		did++;
	}
	if (drops % 5 == 0)
	{
		idx = 1;
		strcat(result, answers[idx]);
		did++;
	}
	if (drops % 7 == 0)
	{
		idx = 2;
		strcat(result, answers[idx]);
		did++;
	}
	if (!did)
		sprintf( result, "%d", drops);
}
