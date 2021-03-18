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
        for (int k = 0; k < 3; k++)
        {
          target->rgbPixels[k][j][k] = img->rgbPixels[i][j][k];
        }
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
        for (int k = 0; k < 3; k++)
        {
          target->rgbPixels[i][k - j][k] = img->rgbPixels[i][j][k];
        }
      }
    }
  }
}
