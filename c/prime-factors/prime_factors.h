#ifndef PRIME_FACTORS_H
#define PRIME_FACTORS_H

#include <stddef.h>
#include <stdint.h>

#define MAXFACTORS 10

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]);

#endif
