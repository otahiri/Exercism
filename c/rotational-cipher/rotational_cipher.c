#include "rotational_cipher.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *rotate(const char *text, int shift_key)
{
	char *res = malloc(sizeof(char) * (strlen(text) + 1));
	int i = 0;
	while (text[i])
	{
		if (isupper(text[i]))
			res[i] = (((((text[i] - 'A') + shift_key) % 26) + 26 ) % 26) + 'A';
		else if (islower(text[i]))
			res[i] = (((((text[i] - 'a') + shift_key) % 26) + 26) % 26) + 'a';
		else
			res[i] = text[i];
		i++;
	}
	res[i] = '\0';
	return res;
}
