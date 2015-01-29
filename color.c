#include "color.h"

color add_color(color a, color b)
{
    // Attention, aucune vérification n'est faite pour assurer que les couleurs soient bien des float compris entre 0 et 1 !
    color m_color;
    m_color.r = (a.r + b.r);
    m_color.g = (a.g + b.g);
    m_color.b = (a.b + b.b);
    return m_color;
}

color mult_color(color c, float factor)
{
    color m_color;
    m_color.r = (c.r)*factor;
    m_color.g = (c.g)*factor;
    m_color.b = (c.b)*factor;
    return m_color;
}

color color_red()
{
    color red;
    red.r = 1;
    red.g = 0;
    red.b = 0;
    return red;
}

color color_green()
{
    color green;
    green.r = 0;
    green.g = 1;
    green.b = 0;
    return green;
}

color color_blue()
{
    color blue;
    blue.r = 0;
    blue.g = 0;
    blue.b = 1;
    return blue;
}

color color_yellow()
{
    color yellow;
    yellow.r = 1;
    yellow.g = 1;
    yellow.b = 0;
    return yellow;
}

float random_float()
{
    return ((float)rand()/(float)(RAND_MAX));
}

color color_gradient(color c0, color c1, int length, int alpha)
{
    float delta = (float)((float)1/(float)length);
    color grad_color;
    grad_color = add_color(mult_color(c0,delta*alpha), mult_color(c1,1-(delta*alpha)));
    return grad_color;
}

color color_sin_gradient(color c0, color c1, float scale, int alpha)
{
    float a1 = (float)(((float)sin(alpha*scale) +1)/(float)2);
    float a2 = 1 - a1;
    color grad_color;
    grad_color = add_color(mult_color(c0,a1), mult_color(c1,a2));
    return grad_color;
}

color random_color()
{
    color m_color;
    m_color.r = random_float();
    m_color.g = random_float();
    m_color.b = random_float();
    return m_color;
}

color random_gradient(int alpha)
{
    srand((unsigned int)alpha);
    return random_color();
    srand((unsigned int)time(NULL));
}

color random_tint(color c)
{
    color m_color = mult_color(c, random_float());
    return m_color;
}

