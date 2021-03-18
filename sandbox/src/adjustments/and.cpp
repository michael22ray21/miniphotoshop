#include "and.hpp"

void ANDAdjustment::apply(IMAGE *image1, IMAGE *image2)
{
    if (image1->height == image2->height && image1->width == image2->width)
    {
        if (image1->pixels == NULL && image2->pixels == NULL)
        {
            for (int i = 0; i < image1->height; i++)
            {
                for (int j = 0; j < image1->width; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        image1->rgbPixels[i][j][k] = image1->rgbPixels[i][j][k] & image2->rgbPixels[i][j][k];
                    }
                }
            }
        }
        else if (image1->pixels != NULL && image2->pixels != NULL)
        {
            for (int i = 0; i < image1->height; i++)
            {
                for (int j = 0; j < image1->width; j++)
                {
                    image1->pixels[i][j] = image1->pixels[i][j] & image2->pixels[i][j];
                }
            }
        }
    }
}