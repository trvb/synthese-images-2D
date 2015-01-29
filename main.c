#include <stdio.h>
#include <math.h>

#include "color.h"
#include "image.h"
#include "effect.h"

int main(void)
{
    srand((unsigned int)time(NULL));

    // init
    int dim = 800;
    image m_image;
    init_image(&m_image, dim, dim);
    int quarter = dim / 4;

    // background
    horizontal_sin_gradient(random_color(), random_color(), m_image);

    // circles
    circle_random_radius(quarter, quarter*3, quarter, 7.0, m_image);
    circle_random_angle(quarter*3, quarter, quarter, m_image);
    circle_random_fill(quarter*3, quarter*3, quarter, 5000, m_image);
    circle_random_awesome(quarter, quarter, quarter, m_image);
    circle_gradient(quarter*2, quarter*2, quarter, random_color(), random_color(), m_image);

    // export
    export_image(m_image, "image.ppm");

    return 0;
}

