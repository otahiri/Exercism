#include "saddle_points.h"

saddle_points_t *saddle_points(size_t width, size_t height, uint8_t **matrix)
{
  size_t idx = 0;
  size_t max_points = (width < height) ? width : height;
  saddle_points_t *points = malloc(sizeof(saddle_points_t *) * max_points);
  points[idx]->x = 0;
  points[idx]->y = 0;
  for (size_t i = 0; i < height; i++)
  {
    for (size_t j = 0; j < width; j++)
    {
      if (matrix[i][j] > matrix[points[idx]->y][points[idx]-> x])
      {
        points[idx]->x = j;
        points[idx]->y = i;
      }
      for (size_t h = 0; h < height; h++)
      {

      }
    }
  }
}
void free_saddle_points(saddle_points_t saddle);
