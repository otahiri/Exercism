#include "nth_prime.h"
#include <math.h>
#include <stdint.h>

int is_prime(uint32_t prime) {
  double fact = sqrt((double)prime);
  for (uint32_t i = 2; i <= fact; i++) {
    if (!(prime % i))
      return 0;
  }
  return 1;
}

uint32_t next_prime(uint32_t prime) {
  prime = (prime % 2) == 0 ? prime + 1 : prime + 2;
  while (!is_prime(prime)) {
    prime += 2;
  }
  return prime;
}

uint32_t nth(uint32_t n) {
  if (n == 0)
    return 0;
  uint32_t prime = 2;
  for (; n > 1; n--) {
    prime = next_prime(prime);
  }
  return prime;
}
