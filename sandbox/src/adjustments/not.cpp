#include "not.hpp"

void NOTAdjustment::apply(IMAGE *image)
{
    for (int i = 0; i < image->height; i++)
    {
        for (int j = 0; j < image->width; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image->rgbPixels[i][j][k] = !image->rgbPixels[i][j][k];
            }
        }
    }
}