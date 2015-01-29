#include "image.h"

int index_pixel(int i, int j, image img)
{
    return (i+(j*(img.width)));
}

void init_image(image *img, int w, int h)
{
    img->width = w;
    img->height = h;
    img->data = malloc((sizeof(color)*w*h)+10);

    color null_color;
    null_color.r = 0;
    null_color.g = 0;
    null_color.b = 0;

    for(int i=0; i<w; i++)
        for(int j=0; j<h; j++)
            img->data[index_pixel(i,j,*img)] = null_color;
}

int export_image(image img, const char* fname)
{
    FILE* fichier = NULL;
    fichier = fopen(fname,"w");

    // magic header
    fprintf(fichier, "P3\n%d %d\n255\n", img.width, img.height);

    // dataaaaz
    for(int i=0; i<img.width; i++)
    {
        for(int j=0; j<img.height; j++)
        {
            fprintf(fichier, "%d %d %d ", (unsigned int)((img.data[index_pixel(i,j,img)].r)*255), (unsigned int)((img.data[index_pixel(i,j,img)].g)*255), (unsigned int)((img.data[index_pixel(i,j,img)].b)*255));
        }
        fprintf(fichier, "\n");
    }

    fclose(fichier);
    return(fichier != NULL);
}
