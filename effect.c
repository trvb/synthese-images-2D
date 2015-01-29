#include "effect.h"

void horizontal_gradient(color c0, color c1, image img)
{
    for(int k=0; k<img.width; k++)
        for(int j=0; j<img.height; j++)
            img.data[index_pixel(k,j,img)] = color_gradient(c0, c1, img.width, k);
}

void horizontal_sin_gradient(color c0, color c1, image img)
{
    for(int k=0; k<img.width; k++)
        for(int j=0; j<img.height; j++)
        {
            img.data[index_pixel(k,j,img)] = color_sin_gradient(c0, c1, 0.1, k);
        }
}

void circle_gradient(int cx, int cy, int r, color c0, color c1, image img)
{
    for(int i=0; i<img.width; i++)
        for(int j=0; j<img.height; j++)
        {
            double dist = sqrt( pow(i-cx,2) + pow(j-cy,2) );
            if(dist < r) img.data[index_pixel(i,j,img)] = color_gradient(c0, c1, r, (int)dist);
        }
}

void circle_random_angle(int cx, int cy, int r, image img)
{
    for(int i=0; i<img.width; i++)
        for(int j=0; j<img.height; j++)
        {
            double dist = sqrt( pow(i-cx,2) + pow(j-cy,2) );
            if(dist < r)
            {
                int point_angle = (float)atan2(cx-i, cy-j)*50;
                img.data[index_pixel(i,j,img)] = random_gradient(point_angle);
            }
        }
}

void circle_random_radius(int cx, int cy, int r, float thickness, image img)
{
    for(int i=0; i<img.width; i++)
        for(int j=0; j<img.height; j++)
        {
            double dist = sqrt( pow(i-cx,2) + pow(j-cy,2) );
            if(dist < r) img.data[index_pixel(i,j,img)] = random_gradient((int)(dist/thickness));
        }
}

void circle_random_fill(int cx, int cy, int r, int block_size, image img)
{
    int block_count = 0;
    color block_color = random_color();

    for(int i=0; i<img.width; i++)
        for(int j=0; j<img.height; j++)
        {
            double dist = sqrt( pow(i-cx,2) + pow(j-cy,2) );
            if(block_count > block_size)
            {
                block_count = 0;
                block_color = random_color();
            } else { block_count++; }
            if(dist < r) img.data[index_pixel(i,j,img)] = block_color;
        }
}

void circle_random_awesome(int cx, int cy, int r, image img)
{
    for(int i=0; i<img.width; i++)
        for(int j=0; j<img.height; j++)
        {
            double dist = sqrt( pow(i-cx,2) + pow(j-cy,2) );
            if(dist < r)
            {
                int point_angle = atan((float)((float)cy-j/(float)cx-i))*1000;
                img.data[index_pixel(i,j,img)] = random_gradient(point_angle);
            }
        }
}
