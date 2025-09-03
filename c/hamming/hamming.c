#include "hamming.h"
#include <string.h>


int compute(const char *lhs, const char *rhs)
{
	int i = 0;
	int count = 0;
	if (strlen(lhs) != strlen(rhs))
		return -1;
	while (lhs[i] && rhs[i])
	{
		if (lhs[i] != rhs[i])
			count++;
		i++;
	}
	return count;
}
