#include "nucleotide_count.h"
#include <math.h>
#include <stdlib.h>

int digits(int n)
{
	if (n == 0)
		return 1;
	return (int)log10(n) + 1;
}

int insert_dig(int num, int idx, char *arr)
{
	int tmp = num;
	int div = 1;
	while (tmp / div >= 10)
		div *= 10;
	arr[idx++] = ':';
	if (num == 0)
		arr[idx++] = '0';
	else
	{
		while (div > 0)
		{
			arr[idx++] = (tmp / div) + '0';
			tmp %= div;
			div /= 10;
		}
	}
	arr[idx++] = ' ';
	return idx;
}

char *count(const char *dna_strand)
{
	char letters[4] = {'A', 'C', 'G', 'T'};
	int count[4] = {0, 0, 0, 0};
	char *res;
	for (int i = 0; dna_strand[i]; i++)
	{
		switch (dna_strand[i])
		{
			case 'A' :
				count[0]++;
				break;
			case 'C' :
				count[1]++;
				break;
			case 'G' :
				count[2]++;
				break;
			case 'T' :
				count[3]++;
				break;
			default :
				res = malloc(sizeof(char) * 1);
				res[0] = '\0';
				return res;
		}
	}
	res = malloc(sizeof(char) * (digits(count[0]) + digits(count[1]) + digits(count[2]) + digits(count[3]) + 12));
	int idx = 0;
	for (int j = 0; j < 4; j++)
	{
		res[idx++] = letters[j];
		idx = insert_dig(count[j], idx, res);
	}
	res[idx - 1] = '\0';
	return res;
}
