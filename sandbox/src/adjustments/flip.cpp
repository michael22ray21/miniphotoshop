#include "flip.hpp"

void FlipAdjustment::verticalFlip(IMAGE *target)
{
  IMAGE *img = new IMAGE(*target);
  int N = img->height, M = img->width;

  int k = M - 1;
  if (target->pixels != NULL)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        target->pixels[k][j] = img->pixels[i][j];
      }
      k--;
    }
  }
  else
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        target->r[k][j] = img->r[i][j];
        target->g[k][j] = img->g[i][j];
        target->b[k][j] = img->b[i][j];
      }
    }
  }
}

void FlipAdjustment::horizontalFlip(IMAGE *target)
{
  IMAGE *img = new IMAGE(*target);
  int N = img->height, M = img->width;

  int k = M - 1;
  if (target->pixels != NULL)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        target->pixels[i][k - j] = img->pixels[i][j];
      }
    }
  }
  else
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        target->r[i][k - j] = img->r[i][j];
        target->g[i][k - j] = img->g[i][j];
        target->b[i][k - j] = img->b[i][j];
      }
    }
  }
}
