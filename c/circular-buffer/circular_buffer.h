#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

typedef uint16_t buffer_value_t;
typedef struct{
  buffer_value_t *buffer;
  size_t head;
  size_t tail;
  size_t size;
  size_t capacity;
}circular_buffer_t;

circular_buffer_t new_circular_buffer(capacity);
void delete_buffer(circular_buffer_t buffer);

#endif
