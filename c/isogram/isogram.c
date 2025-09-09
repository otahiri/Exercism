#include "isogram.h"
#include <ctype.h>


bool is_isogram(const char phrase[])
{
	if (!phrase)
		return false;
	for (int i = 0; phrase[i];i++)
	{
		for (int j = 0; phrase[j]; j++)
		{
			if (!isalpha(phrase[j]))
				continue;
			if (tolower(phrase[i]) == tolower(phrase[j]) && i != j)
				return false;
		}
	}
	return true;
}
