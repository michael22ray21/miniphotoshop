#include "zoom.hpp"

void ZoomAdjustment::zoomOut(IMAGE *target)
{
  IMAGE *img = new IMAGE(*target);
  int N = img->height, M = img->width;

  int m, n;
  m = 0;
  n = 0;
  if (target->pixels != NULL)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        if (m < M && n < N)
        {
          target->pixels[m][n] = img->pixels[i][j];
          target->pixels[m][n + 1] = img->pixels[i][j];
          target->pixels[m + 1][n] = img->pixels[i][j];
          target->pixels[m + 1][n + 1] = img->pixels[i][j];
          n += 2;
        }
      }
      m += 2;
      n = 0;
    }
  }
  else
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        if (m < M && n < N)
        {
          for (int k = 0; k < 3; k++)
          {
            target->rgbPixels[m][n][k] = img->rgbPixels[i][j][k];
            target->rgbPixels[m][n + 1][k] = img->rgbPixels[i][j][k];
            target->rgbPixels[m + 1][n][k] = img->rgbPixels[i][j][k];
            target->rgbPixels[m + 1][n + 1][k] = img->rgbPixels[i][j][k];
          }
          n += 2;
        }
      }
      m += 2;
      n = 0;
    }
  }
}

void ZoomAdjustment::zoomIn(IMAGE *target)
{
  int N = target->height, M = target->width;

  IMAGE *img = new IMAGE(*target);
  int m, n;
  m = 0;
  n = 0;
  if (target->pixels != NULL)
  {
    unsigned char temp[N / 2][M / 2];
    for (int i = 0; i < N; i += 2)
    {
      for (int j = 0; j < M; j += 2)
      {
        int sum = 0;
        sum += target->pixels[i][j];
        sum += target->pixels[i][j + 1];
        sum += target->pixels[i + 1][j];
        sum += target->pixels[i + 1][j + 1];
        temp[i / 2][j / 2] = sum / 4;
      }
    }
    for (int i = 0; i < N / 2; i++)
    {
      for (int j = 0; j < M / 2; j++)
      {
        img->pixels[i][j] = temp[i][j];
      }
    }
  }
  else
  {
    unsigned char temp[N / 2][M / 2][3];
    for (int i = 0; i < N; i += 2)
    {
      for (int j = 0; j < M; j += 2)
      {
        for (int k = 0; k < 3; k++)
        {
          int sum = 0;
          sum += target->rgbPixels[i][j][k];
          sum += target->rgbPixels[i][j + 1][k];
          sum += target->rgbPixels[i + 1][j][k];
          sum += target->rgbPixels[i + 1][j + 1][k];
          temp[i / 2][j / 2][k] = sum / 4;
        }
      }
    }
    for (int i = 0; i < N / 2; i++)
    {
      for (int j = 0; j < M / 2; j++)
      {
        for (int k = 0; k < 3; k++)
        {
          img->rgbPixels[i][j][k] = temp[i][j][k];
        }
      }
    }
  }
  *target = *img;
}