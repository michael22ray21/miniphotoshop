#include <algorithm>
#include <vector>
#include "nonlinear.hpp"

int magn(uchar r, uchar g, uchar b){
  return (r*r + g*g + b*b) / 3;
}

void manualSort(std::vector<uchar> &r, std::vector<uchar> &g, std::vector<uchar> &b){
  std::vector<int> magnitude;
  for (int i = 0; i < r.size(); i++){
    magnitude.push_back(magn(r[i], g[i], b[i]));
  }
  for (int i = 0; i < r.size(); i++){
    int idx = i;
    for (int j = i + 1; j < r.size(); j++){
      if (magnitude[j] < magnitude[idx]){
        idx = j;
      }
    }
    int temp = magnitude[idx];
    magnitude[idx] = magnitude[i];
    magnitude[i] = temp;

    temp = r[idx];
    r[idx] = r[i];
    r[i] = r[idx];

    temp = g[idx];
    g[idx] = g[i];
    g[i] = g[idx];

    temp = b[idx];
    b[idx] = b[i];
    b[i] = b[idx];
  }
}

void applyFilterMedianStrategy(IMAGE* target, int size) {
  IMAGE* temp = new IMAGE(*target);
  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
      std::vector<uchar> pixels;
      std::vector<uchar> r;
      std::vector<uchar> g;
      std::vector<uchar> b;
      int rowOffset = - (size / 2);
      for (int i_k = 0; i_k < (int) size; i_k++) {
        int colOffset = - (size / 2);
        for (int j_k = 0; j_k < (int) size; j_k++) {
          int i_target = std::max(0, std::min(target->height - 1, i + rowOffset + i_k));
          int j_target = std::max(0, std::min(target->width - 1, j + colOffset + j_k));
          if (temp->depth == 1){
            pixels.push_back(temp->pixels[i_target][j_target]);
          } else {
            r.push_back(temp->rgbPixels[i_target][j_target][0]);
            g.push_back(temp->rgbPixels[i_target][j_target][1]);
            b.push_back(temp->rgbPixels[i_target][j_target][2]);
          }
        }
      }
      if(temp->depth == 1){
        sort(pixels.begin(), pixels.end());
        target->pixels[i][j] = pixels[pixels.size() / 2];
      } else {
        manualSort(r, g, b);
        target->rgbPixels[i][j][0] = r[r.size() / 2];
        target->rgbPixels[i][j][1] = g[g.size() / 2];
        target->rgbPixels[i][j][2] = b[b.size() / 2];
      }
    }
  }
  delete temp;
}

void applyFilterMaxStrategy(IMAGE* target, int size) {
  IMAGE* temp = new IMAGE(*target);
  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
      uchar new_pixel[4] = {0,0,0,0};
      int rowOffset = - (size / 2);
      for (int i_k = 0; i_k < (int) size; i_k++) {
        int colOffset = - (size / 2);
        for (int j_k = 0; j_k < (int) size; j_k++) {
          int i_target = std::max(0, std::min(target->height - 1, i + rowOffset + i_k));
          int j_target = std::max(0, std::min(target->width - 1, j + colOffset + j_k));
          if (temp->depth == 1){
            uchar prev = temp->pixels[i_target][j_target];
            if (prev > new_pixel[0]) {
              new_pixel[0] = prev;
            }
          } else {
            uchar prevr = temp->rgbPixels[i_target][j_target][0];
            uchar prevg = temp->rgbPixels[i_target][j_target][1];
            uchar prevb = temp->rgbPixels[i_target][j_target][2];
            if (magn(prevr, prevg, prevb) > magn(new_pixel[0], new_pixel[1], new_pixel[2])) {
              new_pixel[0] = prevr;
              new_pixel[1] = prevg;
              new_pixel[2] = prevb;
            }
          }
        }
      }
      if(temp->depth == 1){
        target->pixels[i][j] = new_pixel[0];
      } else {
        for (int k = 0; k < 3; k++){
          target->rgbPixels[i][j][k] = new_pixel[k];
        }
      }
    }
  }
  delete temp;
}


void applyFilterMinStrategy(IMAGE* target, int size) {
  IMAGE* temp = new IMAGE(*target);
  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
      uchar new_pixel[4] = {255, 255, 255, 0};
      int rowOffset = - (size / 2);
      for (int i_k = 0; i_k < (int) size; i_k++) {
        int colOffset = - (size / 2);
        for (int j_k = 0; j_k < (int) size; j_k++) {
          int i_target = std::max(0, std::min(target->height - 1, i + rowOffset + i_k));
          int j_target = std::max(0, std::min(target->width - 1, j + colOffset + j_k));
          if (temp->depth == 1){
            uchar prev = temp->pixels[i_target][j_target];
            if (prev < new_pixel[0]) {
              new_pixel[0] = prev;
            }
          } else {
            uchar prevr = temp->rgbPixels[i_target][j_target][0];
            uchar prevg = temp->rgbPixels[i_target][j_target][1];
            uchar prevb = temp->rgbPixels[i_target][j_target][2];
            if (magn(prevr, prevg, prevb) < magn(new_pixel[0], new_pixel[1], new_pixel[2])) {
              new_pixel[0] = prevr;
              new_pixel[1] = prevg;
              new_pixel[2] = prevb;
            }
          }
        }
      }
      if(temp->depth == 1){
        target->pixels[i][j] = new_pixel[0];
      } else {
        for (int k = 0; k < 3; k++){
          target->rgbPixels[i][j][k] = new_pixel[k];
        }
      }
    }
  }
  delete temp;
}
