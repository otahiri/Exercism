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
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  while (num <= size * size)
  {
    spiral->matrix[y][x] = num++;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx <= right_bar && nx >= left_bar && ny <= down_bar && ny >= up_bar)
    {
      x = nx;
      y = ny;
    }else{
      switch (dir) {
        case RIGHT: up_bar++; break;
        case DOWN: right_bar--; break;
        case LEFT: down_bar--; break;
        case UP: left_bar++; break;
        default: break;
      }
      dir = (dir + 1) % MAX;
      x += dx[dir];
      y += dy[dir];
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

