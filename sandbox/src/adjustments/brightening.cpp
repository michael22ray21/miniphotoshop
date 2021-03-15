#include "brightening.hpp"

void BrighteningAdjustment::apply(IMAGE *target, int b)
{
    if (target->pixels == NULL)
    {
        for (int i = 0; i < target->height; i++)
        {
            for (int j = 0; j < target->width; j++)
            {
                target->r[i][j] += b;
                target->g[i][j] += b;
                target->b[i][j] += b;
            }
        }
    }
    else
    {
        for (int i = 0; i < target->height; i++)
        {
            for (int j = 0; j < target->width; j++)
            {
                target->pixels[i][j] += b;
            }
        }
    }
}