#include "protein_translation.h"
#include <string.h>

/*typedef enum {
   Methionine,
   Phenylalanine,
   Leucine,
   Serine,
   Tyrosine,
   Cysteine,
   Tryptophan,
} amino_acid_t;

typedef struct {
   bool valid;
   size_t count;
   amino_acid_t amino_acids[MAX_AMINO_ACIDS];
} protein_t;*/

int which_prot(char *str) {
  char *methionine[1] = {"AUG"};
  char *phenylalanine[2] = {"UUU", "UUC"};
  char *leucine[2] = {"UUA", "UUG"};
  char *serine[4] = {"UCU", "UCC", "UCA", "UCG"};
  char *tyrosine[2] = {"UAU", "UAC"};
  char *cysteine[2] = {"UGU", "UGC"};
  char *tryptophan[1] = {"UGG"};
  char *stop[3] = {"UAA", "UAG", "UGA"};
  char **proteins[8] = {methionine, phenylalanine, leucine,    serine,
                        tyrosine,   cysteine,      tryptophan, stop};
  int len[8] = {1, 2, 2, 4, 2, 2, 1, 3};
  for (int g = 0; str[g]; g++) {
    if (str[g] != 'A' && str[g] != 'G' && str[g] != 'U' && str[g] != 'C')
      return -1;
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < len[i]; j++) {
      if (strcmp(str, proteins[i][j]) == 0)
        return i;
    }
  }
  return -1;
}
protein_t protein(const char *const rna) {
  char prot[4];
  protein_t res;
  int idx = 0;
  int num;
  int i = 0;
  res.count = 0;
  for (; rna[i]; i++) {
    prot[i % 3] = rna[i];
    if ((i + 1) % 3 == 0) {
      prot[3] = '\0';
      num = which_prot(prot);
      if (num == -1) {
        res.valid = false;
        return res;
      }
      if (num == 7) {
        res.valid = true;
        return res;
      }

      res.count++;
      res.amino_acids[idx++] = num;
    }
  }
  if (i % 3 != 0) {
    res.valid = false;
    return res;
  }
  res.valid = true;
  return res;
}
