#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>

char *reverse(const char *value)
{
	char *rev = malloc(sizeof(char) * (strlen(value) + 1));
	int ridx = 0;
	int idx = strlen(value) - 1;
	for (; value[ridx]; ridx++)
		rev[ridx] = value[idx--];		
	rev[ridx] = '\0';
	return rev;
}
