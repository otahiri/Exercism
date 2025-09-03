#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>

char *to_rna(const char *dna)
{
	int i = 0;
	char *res = malloc(sizeof(char) * (strlen(dna) + 1));
	while (dna[i])
	{
		if( dna[i] == 'G')
			res[i] = 'C';
		if( dna[i] == 'C')
			res[i] = 'G';
		if( dna[i] == 'T')
			res[i] = 'A';
		if( dna[i] == 'A')
			res[i] = 'U';
		i++;
	}
	res[i] = '\0';
	return res;
}
