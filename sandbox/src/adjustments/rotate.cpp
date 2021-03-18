#include "rotate.hpp"

void RotateAdjustment::rotate90CCW(IMAGE *target)
{
  IMAGE *img = new IMAGE(*target);
  int N = img->height, M = img->width;
  int k = 0;

  if (target->pixels != NULL)
  {
    for (int i = 0; i < N; i++)
    {
      k = M - 1;
      for (int j = 0; j < M; j++)
      {
        target->pixels[k][i] = img->pixels[i][j];
        k--;
      }
    }
  }
  else
  {
    for (int i = 0; i < N; i++)
    {
      k = M - 1;
      for (int j = 0; j < M; j++)
      {
        for (int p = 0; p < 3; p++)
        {
          target->rgbPixels[k][i][p] = img->rgbPixels[i][j][p];
        }
        k--;
      }
    }
  }
  int temp = target->width;
  target->width = target->height;
  target->height = temp;
  delete img;
}

void RotateAdjustment::rotate90CW(IMAGE *target)
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
        target->pixels[j][k] = img->pixels[i][j];
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
        for (int p = 0; p < 3; p++)
        {
          target->rgbPixels[j][k][p] = img->rgbPixels[i][j][p];
        }
      k--;
      }
    }
  }
  int temp = target->width;
  target->width = target->height;
  target->height = temp;
  delete img;
}
