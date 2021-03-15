#include "or.hpp"

void apply(IMAGE *image1, IMAGE *image2)
{
    if (image1->height == image2->height && image1->width == image2->width)
    {
        if (image1->pixels == NULL && image2->pixels == NULL)
        {
            for (int i = 0; i < image1->height; i++)
            {
                for (int j = 0; j < image1->width; j++)
                {
                    image1->r[i][j] = image1->r[i][j] | image2->r[i][j];
                    image1->g[i][j] = image1->g[i][j] | image2->g[i][j];
                    image1->b[i][j] = image1->b[i][j] | image2->b[i][j];
                }
            }
        }
        else if (image1->pixels != NULL && image2->pixels != NULL)
        {
            for (int i = 0; i < image1->height; i++)
            {
                for (int j = 0; j < image1->width; j++)
                {
                    image1->pixels[i][j] = image1->pixels[i][j] | image2->pixels[i][j];
                }
            }
        }
    }
}