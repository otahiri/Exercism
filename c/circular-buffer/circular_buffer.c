#include "circular_buffer.h"

circular_buffer_t *new_circular_buffer(size_t capacity)
{
  if (!capacity)
    return NULL;
  circular_buffer_t *circ;
  circ = calloc(1, sizeof(circular_buffer_t));
  if (!circ)
    return NULL;
  circ->buffer = calloc(capacity, sizeof(buffer_value_t));
  if (!circ->buffer)
  {
    free(circ);
    return NULL;
  }
  circ->capacity = capacity;
  return circ;
}

void delete_buffer(circular_buffer_t *buffer)
{
  free(buffer->buffer);
  free(buffer);
}

int16_t write(circular_buffer_t *buffer, buffer_value_t value)
{
  if (buffer->size == buffer->capacity)
  {   
    errno = ENOBUFS;
    return EXIT_FAILURE;
  }
  buffer->buffer[buffer->head] = value;
  buffer->head = (buffer->head + 1) % buffer->capacity;
  buffer->size++;
  return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value)
{
  if (buffer->size == buffer->capacity)
  {
    buffer->buffer[buffer->head] = value;
    buffer->tail = (buffer->tail + 1) % buffer->capacity;
    buffer->head = (buffer->head + 1) % buffer->capacity;
    return EXIT_SUCCESS;
  }
  buffer->buffer[buffer->head] = value;
  buffer->head = (buffer->head + 1) % buffer->capacity;
  buffer->size++;
  return EXIT_SUCCESS;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t *read_value)
{
  if (!buffer->size)
  {
    errno = ENODATA;
    return EXIT_FAILURE;
  }
  *read_value = buffer->buffer[buffer->tail];
  buffer->tail = (buffer->tail + 1) % buffer->capacity;
  buffer->size--;
  return EXIT_SUCCESS;
}

void clear_buffer(circular_buffer_t *buffer)
{
  buffer->size = 0;
  buffer->head = 0;
  buffer->tail = 0;
}
