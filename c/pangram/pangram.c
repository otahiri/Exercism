#include "pangram.h"
#include <ctype.h>
#include <stdlib.h>

bool is_pangram(const char *sentence)
{
	if (sentence == NULL)
		return false;
	int count = 0;
	char c;
	const char alpha[] = "abcdefghijklmnopqrstuvwxyz";
	for  (int i = 0; alpha[i]; i++)
	{
		for (int j = 0; sentence[j]; j++)
		{
			if (sentence[j] >= 'A' && sentence[j] <= 'Z')
				c = tolower((unsigned char)sentence[j]);
			else
				c = sentence[j];
			if (c == alpha[i])
			{
				count++;
				break;
			}	
		}
	}
	if (count >= 26)
		return true;
	return false;
}
