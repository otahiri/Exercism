#include "scrabble_score.h"
#include <ctype.h>

int is_in_str(char *str, char c) {
  for (int i = 0; str[i]; i++) {
    if (str[i] == toupper(c))
      return 1;
  }
  return 0;
}

unsigned int score(const char *word) {
  char *chars[7] = {"AEIOULNRST", "DG", "BCMP", "FHVWY", "K", "JX", "QZ"};
  int scores[7] = {1, 2, 3, 4, 5, 8, 10};
  int res = 0;
  for (int i = 0; word[i]; i++) {
    for (int j = 0; j < 7; j++)
      if (is_in_str(chars[j], word[i]))
        res += scores[j];
  }
  return res;
}
