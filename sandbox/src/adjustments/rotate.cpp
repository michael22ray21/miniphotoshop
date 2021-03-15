#include "rotate.hpp"

void RotateAdjustment::rotate90CCW(IMAGE *target)
{
  IMAGE *img = new IMAGE(*target);
  int N = img->height, M = img->width;
  int k;

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
      for (int j = 0; j < M; j++)
      {
        target->r[k][i] = img->r[i][j];
        target->g[k][i] = img->g[i][j];
        target->b[k][i] = img->b[i][j];
      }
    }
  }
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
        target->r[j][k] = img->r[i][j];
        target->g[j][k] = img->g[i][j];
        target->b[j][k] = img->b[i][j];
      }
    }
  }
  delete img;
}
