#include "two_fer.h"

void two_fer(char *buffer, const char *name)
{
	int i = 0;
	int j = 0;
	char *defult = "you";
	char *strp1 = "One for ";
	char *strp2 = ", one for me.";
	if (name == NULL)
		name = defult;
	while (strp1[j])
	{
		buffer[i] = strp1[j];
		i++;
		j++;
	}
	j = 0;
	while (name[j])
	{
		buffer[i] = name[j];
		i++;
		j++;
	}
	j = 0;
	while (strp2[j])
	{
		buffer[i] =strp2[j];
		i++;
		j++;
	}
	buffer[i] = '\0';
}
