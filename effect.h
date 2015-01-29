#ifndef EFFECT_H
#define EFFECT_H

#include "color.h"
#include "image.h"
#include "math.h"

void horizontal_gradient(color c0, color c1, image img);
void horizontal_sin_gradient(color c0, color c1, image img);
void circle_gradient(int cx, int cy, int r, color c0, color c1, image img);
void circle_random_fill(int cx, int cy, int r, int block_size, image img);
void circle_random_radius(int cx, int cy, int r, float thickness, image img);
void circle_random_angle(int cx, int cy, int r, image img);
void circle_random_awesome(int cx, int cy, int r, image img);

#endif

