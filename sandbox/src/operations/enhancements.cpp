#include "enhancements.hpp"
#include "../utils/math.hpp"
#include <cmath>

void brighten(IMAGE *target, double multiplier) {  
  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
        if (target->rgbPixels == NULL){
            target->pixels[i][j] = clip((int) target->pixels[i][j] * multiplier, 0, 255);
        } else {
            for (int k = 0; k < 3; k++){
                target->rgbPixels[i][j][k] = clip((int) target->rgbPixels[i][j][k] * multiplier, 0, 255);
            }
        }
    }
  }
}

void contrastStretch(IMAGE* target, int rMin, int rMax) {
  int range = rMax - rMin, depth=0;
  if (target->rgbPixels == NULL){
    depth = 1;
  } else {
    depth = 3;
  }

  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
        if (depth == 1){
            uchar px = target->pixels[i][j];
            if ( px < rMin)
                px = 0;
            else if (px > rMax)
                px = 255;
            else
                px = clip(round((double) (px - rMin)*255/range), 0, 255);

            target->pixels[i][j] = px;
        } else{
            for (int k = 0; k < 3; k++){
                uchar rgb = target->rgbPixels[i][j][k];
                if ( rgb < rMin)
                    rgb = 0;
                else if (rgb > rMax)
                    rgb = 255;
                else
                    rgb = clip(round((double) (rgb - rMin)*255/range), 0, 255);
                target->rgbPixels[i][j][k] = rgb;
            }
        }
    }
  }
}

void logTransform(IMAGE* target, double c) {
  int depth=0;
  if (target->rgbPixels == NULL){
    depth = 1;
  } else {
    depth = 3;
  }

  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
        if (depth == 1){
            uchar px = target->pixels[i][j];
            px = clip((int)c * log(1 + px), 0, 255);
            target->pixels[i][j] = px;
        } else {
            for (int k = 0; k < 3; k++){
                uchar rgb = target->rgbPixels[i][j][k];
                rgb = clip((int)c * log(1 + rgb), 0, 255);
                target->rgbPixels[i][j][k] = rgb;
            }
        }
        
    }
  }
}

void inverseLog(IMAGE* target, double c) {
    int depth=0;
    if (target->rgbPixels == NULL){
        depth = 1;
    } else {
        depth = 3;
    }

    for (int i = 0; i < target->height; i++) {
        for (int j = 0; j < target->width; j++) {
            if (depth == 1){
                uchar px = target->pixels[i][j];
                px = clip((int)c * (exp(px)-1), 0, 255);
                target->pixels[i][j] = px;
            } else {
                for (int k = 0; k < 3; k++){
                    uchar rgb = target->rgbPixels[i][j][k];
                    rgb = clip((int)c * (exp(rgb)-1), 0, 255);
                    target->rgbPixels[i][j][k] = rgb;
                }
            }
        }
    }
}

void power(IMAGE* target, double c) {
  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
        if (target->rgbPixels == NULL){
            uchar px = target->pixels[i][j];
            target->pixels[i][j] = clip(round((double) pow(px, c)), 0, 255);
        } else {
            for (int k = 0; k < 3; k++){
                uchar rgb = target->rgbPixels[i][j][k];
                target->rgbPixels[i][j][k] = clip(round((double) pow(rgb, c)), 0, 255);
            }
        }
    }
  }
}

void graySlicing(IMAGE* target, int rMin, int rMax) {
  int depth=0;
    if (target->rgbPixels == NULL){
        depth = 1;
    } else {
        depth = 3;
    }

  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
        if (depth == 1){
            uchar px = target->pixels[i][j];
            if (px > rMin && px<rMax)
                px = 255;
            else
                px = 0;
            target->pixels[i][j] = px;
        } else {
            for (int k = 0; k < 3; k++){
                uchar rgb = target->rgbPixels[i][j][k];
                if (rgb > rMin && rgb<rMax)
                    rgb = 255;
                else
                    rgb = 0;
                target->rgbPixels[i][j][k] = rgb;
            }
        }
    }
  }
}

void bitSlicing(IMAGE* target, int bit) {
    int depth=0;
    if (target->rgbPixels == NULL){
        depth = 1;
    } else {
        depth = 3;
    }

    for (int i = 0; i < target->height; i++) {
        for (int j = 0; j < target->width; j++) {
            if (depth == 1){
                uchar px = target->pixels[i][j];
                if (px & (1<<bit))
                    px = 255;
                else
                    px = 0;
                target->pixels[i][j] = px;
            } else {
                for (int k = 0; k < 3; k++){
                    uchar rgb = target->rgbPixels[i][j][k];
                    if (rgb & (1<<bit))
                        rgb = 255;
                    else
                        rgb = 0;
                    target->rgbPixels[i][j][k] = rgb;
                }
            }
        }
    }
}
