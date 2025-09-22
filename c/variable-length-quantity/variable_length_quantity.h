#ifndef VARIABLE_LENGTH_QUANTITY_H
#define VARIABLE_LENGTH_QUANTITY_H

#include <stddef.h>
#include <stdint.h>

/// Encode an array of integers into Variable Length Quantity.
///
/// The function returns the size of the output buffer used.
int encode(const uint32_t *integers, size_t integers_len, uint8_t *output);

int encode_int(uint32_t integer, uint8_t *res);
/// Decode a Variable Length Quantity byte array into an array of integers.
///
/// The function returns the size of the output buffer used or -1 if an error
/// occurred.
int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output);

#endif
