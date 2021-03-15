#include <algorithm>
#include "equalizations.hpp"
#include "../utils/math.hpp"

int** createHistogramDistribution(IMAGE* source) {
    int depth = 0;
    int** probs;
    if (source->rgbPixels == NULL){
        depth = 1;
        probs = new int*[1];
        probs[0] = new int[256];
        for (int i = 0; i < 256; i++){
            probs[0][i] = 0;
        }
    } else {
        depth = 3;
        probs = new int*[3];
        for (int k = 0; k < 3; k++){
            probs[k] = new int[256];
            for (int i = 0; i < 256; i++){
                probs[k][i] = 0;
            }
        }
    }

    if (depth == 1){
        for (int i = 0; i < source->height; i++) {
            for (int j = 0; j < source->width; j++) {
                uchar px = source->pixels[i][j];
                probs[0][px] += 1;
            }
        }
    }else{
        for (int i = 0; i < source->height; i++) {
            for (int j = 0; j < source->width; j++) {
                for (int k = 0; k < 3; k++){
                    uchar rgb = source->rgbPixels[i][j][k];
                    probs[k][rgb] += 1;
                }
            }
        }
    }

    // questionable 
    if (depth == 1){
        for (int i = 1; i < 256; i++){
            probs[0][i] += probs[0][i-1];
        }
        
    } else {
        for (int i = 1; i < 256; i++){
            for (int k = 0; k < 3; k++){
                probs[k][i] += probs[k][i-1];
            }
        }
    }

  return probs;
}

void applyHistogramEqualization(IMAGE* target) {
    int pxlen = 0;
    if (target->rgbPixels == NULL){
        pxlen = 1;
    } else {
        pxlen = 3;
    }

    int** probs = createHistogramDistribution(target);

    int dimen = target->width * target->height;
    for (int i = 0; i < target->height; i++) {
        for (int j = 0; j < target->width; j++) {
            uchar px, rgb;
            if (pxlen == 1){
                px = target->pixels[i][j];
                target->pixels[i][j] = clip((int) probs[0][px] * 255 / dimen, 0, 255);
            } else {
                for (int k = 0; k < 3; k++){
                    rgb = target->rgbPixels[i][j][k];
                    target->rgbPixels[i][j][k] = clip((int) probs[k][rgb] * 255 / dimen, 0, 255);
                }
            }
        }
    }

    for (int k = 0; k < pxlen; k++) {
        delete[] probs[k];
    }
    delete[] probs;
}

void applyHistogramSpecification(IMAGE* target, IMAGE* specification) {
    int pxlen = 0;
    if (target->rgbPixels == NULL){
        pxlen = 1;
    } else {
        pxlen = 3;
    }

  int** probsTarget = createHistogramDistribution(target);
  int** probsSpecification = createHistogramDistribution(specification);

  int** conversionTarget = new int*[pxlen];
  int** conversionSpecification = new int*[pxlen];

  for (int k = 0; k < pxlen; k++) {
    conversionTarget[k] = new int[256];
    conversionSpecification[k] = new int[256];

    for (int j = 0; j < 256; j++) {
      conversionTarget[k][j] = 0;
      conversionSpecification[k][j] = 0;
    }
  }

  int dimen = target->width * target->height;
  for (int k = 0; k < pxlen; k++) {
    for (int i = 0; i < 256; i++) {
      int newValSpecification = clip((int) probsSpecification[k][i] * 255 / dimen, 0, 255);
      conversionSpecification[k][newValSpecification] = i;
    }
    for (int i = 1; i < 256; i++) {
      conversionSpecification[k][i] = std::max(conversionSpecification[k][i], conversionSpecification[k][i - 1]);
    }
  }

  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
      uchar px, rgb;
      if (pxlen == 3) {
            for (int k = 0; k < 3; k++){
                rgb = target->rgbPixels[i][j][k];
                target->rgbPixels[i][j][k] = conversionSpecification[k][clip((int) probsTarget[k][rgb] * 255 / dimen, 0, 255)];
            }
      } else {
            px = target->pixels[i][j];
            target->pixels[i][j] = conversionSpecification[0][clip((int) probsTarget[0][px] * 255 / dimen, 0, 255)];
      }
    }
  }

  for (int k = 0; k < pxlen; k++) {
    delete[] probsTarget[k];
    delete[] probsSpecification[k];
  }
  delete[] probsTarget;
  delete[] probsSpecification;
  delete[] conversionTarget;
  delete[] conversionSpecification;
}
