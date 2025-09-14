#include <stdio.h>

int main()
{
	char str[10] = "hello";
	char *pt = str;
	char *lpt = str;
	char temp;
	int len = 0;

	while (*lpt != '\0')
	{
		lpt++;
		len++;
	}
	printf("len is %d", len);
	lpt--;
	while (pt <= lpt)
	{
		temp = *pt;
		*pt = *lpt;
		*lpt = temp;
		pt++;
		lpt--;
	}
	printf("str is %s", str);
}
