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
	while (div > 0)
	{
		arr[idx++] = (tmp / div) + '0';
		tmp %= div;
		div /= 10;
	}
	return idx;
}

char *count(const char *dna_strand)
{
	int A = 0;
	int C = 0;
	int G = 0;
	int T = 0;
	char *res;
	for (int i = 0; dna_strand[i]; i++)
	{
		switch (dna_strand[i])
		{
			case 'A' :
				A++;
				break;
			case 'C' :
				C++;
				break;
			case 'G' :
				G++;
				break;
			case 'T' :
				T++;
				break;
			default :
				res = malloc(sizeof(char) * 1);
				res[0] = '\0';
				return res;
		}
	}
	res = malloc(sizeof(char) * (digits(A) + digits(C) + digits(G) + digits(T) + 12));
	int idx = 0;
	res[idx++] = 'A';
	idx = insert_dig(A, idx, res);
	res[idx++] = ' ';
	res[idx++] = 'C';
	idx = insert_dig(C, idx, res);
	res[idx++] = ' ';
	res[idx++] = 'G';
	idx = insert_dig(G, idx, res);
	res[idx++] = ' ';
	res[idx++] = 'T';
	idx = insert_dig(T, idx, res);
	res[idx] = '\0';
	return res;
}
