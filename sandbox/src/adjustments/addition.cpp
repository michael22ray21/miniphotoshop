#include "addition.hpp"
#include "../utils/math.hpp"

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
                    image1->r[i][j] = clip(image1->r[i][j] + image2->r[i][j], 0, 255);
                    image1->g[i][j] = clip(image1->g[i][j] + image2->g[i][j], 0, 255);
                    image1->b[i][j] = clip(image1->b[i][j] + image2->b[i][j], 0, 255);
                }
            }
        }
        else if (image1->pixels != NULL && image2->pixels != NULL)
        {
            for (int i = 0; i < image1->height; i++)
            {
                for (int j = 0; j < image1->width; j++)
                {
                    image1->pixels[i][j] = clip(image1->pixels[i][j] + image2->pixels[i][j], 0, 255);
                }
            }
        }
    }
}