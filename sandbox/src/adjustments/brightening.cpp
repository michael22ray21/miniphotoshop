#include "brightening.hpp"

void BrighteningAdjustment::apply(IMAGE *target, int b)
{
    if (target->pixels == NULL)
    {
        for (int i = 0; i < target->height; i++)
        {
            for (int j = 0; j < target->width; j++)
            {
                for (int k = 0; k < 3; k++)
                    {
                        target->rgbPixels[i][j][k] += b;
                    }
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