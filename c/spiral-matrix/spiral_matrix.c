#include "spiral_matrix.h"
#include <stdlib.h>
#include <stdio.h>

spiral_matrix_t *spiral_matrix_create(int size)
{
  if (size == 0)
  {
    spiral_matrix_t *spiral = malloc(sizeof(spiral_matrix_t));
    spiral->size = 0;
    spiral->matrix = NULL;
    return spiral;
  }
  spiral_matrix_t *spiral = malloc(sizeof(spiral_matrix_t));
  spiral->size = size;
  spiral->matrix = malloc(sizeof(int*) * size);
  for (int i = 0; i < size; i++)
    spiral->matrix[i] = malloc(sizeof(int) * size);
  int x = 0;
  int y = 0;
  dir_t dir = RIGHT;
  int left_bar = 0;
  int right_bar = size - 1;
  int up_bar = 0;
  int down_bar = size - 1;
  int num = 1;
  while (num <= size * size)
  {
    if (x < 0 || y < 0 || x >= size || y >= size) {
      printf("OUT OF BOUNDS: x=%d y=%d num=%d dir=%d\n", x, y, num, dir);
      break;
    }
      spiral->matrix[y][x] = num++;
    switch (dir) {
      case RIGHT:
        if (x < right_bar)
          x++;
        else {
          dir = (dir + 1) % MAX;
          up_bar++;
          y++;
        }
        break;
      case DOWN:
        if (y < down_bar)
          y++;
        else {
          dir = (dir + 1) % MAX;
          right_bar--;
          x--;
        }
        break;
      case LEFT:
        if (x > left_bar)
          x--;
        else{
          dir = (dir + 1) % MAX;
          down_bar--;
          y--;
        }
       break;
      case UP:
        if (y > up_bar)
          y--;
        else{
          dir = (dir + 1) % MAX;
          left_bar++;
          x++;
        }
        break;
      default:
        break;
      }
  }
    return spiral;
}

void spiral_matrix_destroy(spiral_matrix_t *spiral)
{
    for (int i = 0; i < spiral->size; i++)
      free(spiral->matrix[i]);
    free(spiral->matrix);
  }

