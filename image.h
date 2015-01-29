#ifndef IMAGE_H
#define IMAGE_H

#include "stdio.h"
#include "color.h"

typedef struct image_h {
    int width;
    int height;
    color *data;
} image;

int index_pixel(int i, int j, image img);
void init_image(image *img, int w, int h);
int export_image(image img, const char* fname);

#endif

