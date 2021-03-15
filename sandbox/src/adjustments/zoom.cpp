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
          target->r[m][n] = img->r[i][j];
          target->g[m][n] = img->g[i][j];
          target->b[m][n] = img->b[i][j];
          target->r[m][n + 1] = img->r[i][j];
          target->g[m][n + 1] = img->g[i][j];
          target->b[m][n + 1] = img->b[i][j];
          target->r[m + 1][n] = img->r[i][j];
          target->g[m + 1][n] = img->g[i][j];
          target->b[m + 1][n] = img->b[i][j];
          target->r[m + 1][n + 1] = img->r[i][j];
          target->g[m + 1][n + 1] = img->g[i][j];
          target->b[m + 1][n + 1] = img->b[i][j];
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
        int sum = 0;
        sum += target->r[i][j];
        sum += target->r[i][j + 1];
        sum += target->r[i + 1][j];
        sum += target->r[i + 1][j + 1];
        temp[i / 2][j / 2][0] = sum / 4;

        sum = 0;
        sum += target->g[i][j];
        sum += target->g[i][j + 1];
        sum += target->g[i + 1][j];
        sum += target->g[i + 1][j + 1];
        temp[i / 2][j / 2][1] = sum / 4;

        sum = 0;
        sum += target->b[i][j];
        sum += target->b[i][j + 1];
        sum += target->b[i + 1][j];
        sum += target->b[i + 1][j + 1];
        temp[i / 2][j / 2][2] = sum / 4;
      }
    }
    for (int i = 0; i < N / 2; i++)
    {
      for (int j = 0; j < M / 2; j++)
      {
        img->r[i][j] = temp[i][j][0];
        img->g[i][j] = temp[i][j][1];
        img->b[i][j] = temp[i][j][2];
      }
    }
  }
  *target = *img;
}