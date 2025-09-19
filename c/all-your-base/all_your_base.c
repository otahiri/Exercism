#include "all_your_base.h"
#include <math.h>
#include <stddef.h>
#include <stdint.h>

size_t rebase(int8_t digits[], int16_t input_base, int16_t output_base,
              size_t input_length) {
  if (input_base < 2 || output_base < 2 || input_length < 1)
    goto ERR;
  int32_t num = 0;
  for (size_t i = 0; i < input_length; i++) {
    if (digits[i] < 0 || digits[i] >= input_base)
      goto ERR;
    num *= input_base;
    num += digits[i];
  }
  int32_t digit_count = 0;
  for (; pow(output_base, digit_count + 1) < num; digit_count++)
    ;
  size_t output = digit_count + 1;
  for (size_t i = digit_count; i + 1 > 0; i--) {
    digits[i] = num % output_base;
    num /= output_base;
  }
  return output;
ERR:
  digits[0] = 0;
  return 0;
}
