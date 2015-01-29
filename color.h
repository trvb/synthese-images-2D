#ifndef COLOR
#define COLOR

#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct color {
    float r;
    float g;
    float b;
} color;

color add_color(color a, color b);
color mult_color(color c, float factor);

// useful constant colors
color color_red();
color color_green();
color color_blue();
color color_yellow();

color random_color();
color random_tint(color c);
color color_gradient(color c0, color c1, int length, int alpha);
color color_sin_gradient(color c0, color c1, float scale, int alpha);
color random_gradient(int alpha);

#endif

