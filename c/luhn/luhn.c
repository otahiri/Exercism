#include "luhn.h"
#include <ctype.h>
#include <string.h>

bool luhn(const char *num) {
  int sum = 0;
  int doub = 0;
  int i = strlen(num) - 1;
  int len = 0;
  for (; i >= 0; i--) {
    if ((!isdigit(num[i]) && num[i] != ' '))
      return false;
    if (num[i] == ' ')
      continue;
    int digit = num[i] - '0';
    len++;
    if (doub) {
      int dbl = digit * 2;
      sum += dbl % 10 + dbl / 10;
    }
    if (!doub) {
      sum += digit;
    }
    doub = !doub;
  }
  return !(sum % 10) && (len - 1);
}
