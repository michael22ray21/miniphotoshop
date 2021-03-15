#include "enhancements.hpp"
#include "../utils/math.hpp"
#include <cmath>

void brighten(IMAGE *target, double multiplier) {  
  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
        if (target->r == NULL){
            target->pixels[i][j] *= multiplier;
        } else {
            target->r[i][j] *= multiplier;
            target->g[i][j] *= multiplier;
            target->b[i][j] *= multiplier;
        }
    }
  }
}

void contrastStretch(IMAGE* target, int rMin, int rMax) {
  int range = rMax - rMin, depth=0;
  if (target->r == NULL){
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
                px = (px - rMin)*255/range;

            target->pixels[i][j] = px;
        } else{
            uchar r = target->r[i][j];
            if ( r < rMin)
                r = 0;
            else if (r > rMax)
                r = 255;
            else
                r = (r - rMin)*255/range;

            uchar g = target->g[i][j];
            if ( g < rMin)
                g = 0;
            else if (g > rMax)
                g = 255;
            else
                g = (g - rMin)*255/range;

            uchar b = target->b[i][j];
            if ( b < rMin)
                b = 0;
            else if (b > rMax)
                b = 255;
            else
                b = (b - rMin)*255/range;

            target->r[i][j] = r;
            target->g[i][j] = g;
            target->b[i][j] = b;
        }
    }
  }
}

void logTransform(IMAGE* target, double c) {
  int depth=0;
  if (target->r == NULL){
    depth = 1;
  } else {
    depth = 3;
  }

  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
        if (depth == 1){
            uchar px = target->pixels[i][j];
            px = c * log(1 + px);
            target->pixels[i][j] = px;
        } else {
            uchar r = target->r[i][j];
            r = c * log(1 + r);
            target->r[i][j] = r;

            uchar g = target->g[i][j];
            g = c * log(1 + g);
            target->g[i][j] = g;

            uchar b = target->b[i][j];
            b = c * log(1 + b);
            target->b[i][j] = b;
        }
        
    }
  }
}

void inverseLog(IMAGE* target, double c) {
    int depth=0;
    if (target->r == NULL){
        depth = 1;
    } else {
        depth = 3;
    }

    for (int i = 0; i < target->height; i++) {
        for (int j = 0; j < target->width; j++) {
            if (depth == 1){
                uchar px = target->pixels[i][j];
                px = c * (exp(px)-1);
                target->pixels[i][j] = px;
            } else {
                uchar r = target->r[i][j];
                r = c * (exp(r)-1);
                target->r[i][j] = r;

                uchar g = target->g[i][j];
                g = c * (exp(g)-1);
                target->g[i][j] = g;

                uchar b = target->b[i][j];
                b = c * (exp(b)-1);
                target->b[i][j] = b;
            }
            
        }
    }
}

void power(IMAGE* target, double c) {
  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
        if (target->r == NULL){
            uchar px = target->pixels[i][j];
            target->pixels[i][j] = clip(round((double) pow(px, c)), 0, 255);
        } else {
            uchar r = target->pixels[i][j];
            target->pixels[i][j] = clip(round((double) pow(r, c)), 0, 255);
            uchar g = target->pixels[i][j];
            target->pixels[i][j] = clip(round((double) pow(g, c)), 0, 255);
            uchar b = target->pixels[i][j];
            target->pixels[i][j] = clip(round((double) pow(b, c)), 0, 255);
        }
    }
  }
}

void graySlicing(IMAGE* target, int rMin, int rMax) {
  int depth=0;
    if (target->r == NULL){
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
            uchar r = target->r[i][j];
            if (r > rMin && r<rMax)
                r = 255;
            else
                r = 0;
            target->r[i][j] = r;
            uchar g = target->g[i][j];
            if (g > rMin && g<rMax)
                g = 255;
            else
                g = 0;
            target->g[i][j] = g;
            uchar b = target->b[i][j];
            if (b > rMin && b<rMax)
                b = 255;
            else
                b = 0;
            target->pixels[i][j] = b;
        }
    }
  }
}

void bitSlicing(IMAGE* target, int bit) {
    int depth=0;
    if (target->r == NULL){
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
                uchar r = target->r[i][j];
                if (r & (1<<bit))
                    r = 255;
                else
                    r = 0;
                target->r[i][j] = r;
                uchar g = target->g[i][j];
                if (g & (1<<bit))
                    g = 255;
                else
                    g = 0;
                target->g[i][j] = g;
                uchar b = target->b[i][j];
                if (b & (1<<bit))
                    b = 255;
                else
                    b = 0;
                target->pixels[i][j] = b;
            }
        }
    }
}

