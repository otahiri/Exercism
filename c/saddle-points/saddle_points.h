#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stdlib.h>
typedef struct{
  size_t x;
  size_t y;
}saddle_point_t;

saddle_points_t *saddle_points(size_t width, size_t height, uint8_t *matrix);
saddle_points_t *init_saddle_point(size_t count);
void free_saddle_points(saddle_points_t saddle);


#endif
