#include "not.hpp"

void apply(IMAGE *image)
{
    for (int i = 0; i < image->height; i++)
    {
        for (int j = 0; j < image->width; j++)
        {
            image->r[i][j] = !image->r[i][j];
            image->g[i][j] = !image->g[i][j];
            image->b[i][j] = !image->b[i][j];
        }
    }
}