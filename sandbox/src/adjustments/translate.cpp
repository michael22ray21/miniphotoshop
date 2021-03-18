#include "translate.hpp"

void TranslateAdjustment::apply(IMAGE *target, int m, int n)
{
  IMAGE *img = new IMAGE(*target);
  int N = img->height, M = img->width;

  if (target->pixels != NULL)
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        int target_row = i - m, target_column = j - n;
        if (target_row >= M || target_row < 0 || target_column >= N || target_column < 0)
        {
          target->pixels[i][j] = 0;
        }
        else
        {
          target->pixels[i][j] = img->pixels[target_row][target_column];
        }
      }
    }
  }
  else
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        int target_row = i - m, target_column = j - n;
        if (target_row >= M || target_row < 0 || target_column >= N || target_column < 0)
        {
          for (int k = 0; k < 3; k++)
          {
            target->rgbPixels[i][j][k] = 0;
          }
        }
        else
        {
          for (int k = 0; k < 3; k++)
          {
            target->rgbPixels[i][j][k] = img->rgbPixels[target_row][target_column][k];
          }
        }
      }
    }
  }
}
