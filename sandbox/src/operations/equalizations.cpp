#include <algorithm>
#include "equalizations.hpp"
#include "../utils/math.hpp"

int** createHistogramDistribution(IMAGE* source) {
    int depth = 0;
    int** probs;
    if (source->r == NULL){
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
                uchar r = source->r[i][j];
                probs[0][r] += 1;
                uchar g = source->g[i][j];
                probs[1][g] += 1;
                uchar b = source->b[i][j];
                probs[2][b] += 1;
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
            probs[0][i] += probs[0][i-1];
            probs[1][i] += probs[1][i-1];
            probs[2][i] += probs[2][i-1];
        }
    }

  return probs;
}

void applyHistogramEqualization(IMAGE* target) {
    int pxlen = 0;
    if (target->r == NULL){
        pxlen = 1;
    } else {
        pxlen = 3;
    }

    int** probs = createHistogramDistribution(target);

    int dimen = target->width * target->height;
    for (int i = 0; i < target->height; i++) {
        for (int j = 0; j < target->width; j++) {
            uchar px, r, g, b;
            if (pxlen == 1){
                px = target->pixels[i][j];
            } else {
                r = target->r[i][j];
                g = target->g[i][j];
                b = target->b[i][j];
            }

            if (pxlen == 3) {
                target->r[i][j] = clip((int) probs[0][r] * 255 / dimen, 0, 255);
                target->g[i][j] = clip((int) probs[1][g] * 255 / dimen, 0, 255);
                target->b[i][j] = clip((int) probs[2][b] * 255 / dimen, 0, 255);
            } else {
                target->pixels[i][j] = clip((int) probs[0][px] * 255 / dimen, 0, 255);
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
    if (target->r == NULL){
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
      uchar px, r, g, b;
      if (pxlen == 3) {
            r = target->r[i][j];
            target->r[i][j] = conversionSpecification[0][clip((int) probsTarget[0][r] * 255 / dimen, 0, 255)];
            g = target->g[i][j];
            target->g[i][j] = conversionSpecification[0][clip((int) probsTarget[0][g] * 255 / dimen, 0, 255)];
            b = target->b[i][j];
            target->b[i][j] = conversionSpecification[0][clip((int) probsTarget[0][b] * 255 / dimen, 0, 255)];
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
