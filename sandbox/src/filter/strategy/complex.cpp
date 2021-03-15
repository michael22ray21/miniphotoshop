#include "complex.hpp"
#include "convolution.hpp"
#include "../../utils/math.hpp"

void applyFilterUnsharpStrategy(IMAGE* target){
  Kernel averageKernel;
  averageKernel.assign(5, std::vector<double>());
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      averageKernel[i].push_back(0.04);
    }
  }

  IMAGE* lowPass = new IMAGE(*target);
  applyFilterConvolutionStrategy(lowPass, averageKernel);

  IMAGE* highPass = new IMAGE(*target);
  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
      if (highPass->rgbPixels == NULL){
        highPass->pixels[i][j] = clip((int) target->pixels[i][j] - lowPass->pixels[i][j], 0, 255);
      }else{
        for (int k = 0; k < 3; k++){
          highPass->rgbPixels[i][j][k] = clip((int) target->rgbPixels[i][j][k] - lowPass->rgbPixels[i][j][k], 0, 255);
        }
      }
    }
  }

  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
      if (highPass->rgbPixels == NULL){
        target->pixels[i][j] = clip((int) target->pixels[i][j] + highPass->pixels[i][j], 0, 255);
      }else{
        for (int k = 0; k < 3; k++){
          target->rgbPixels[i][j][k] = clip((int) target->rgbPixels[i][j][k] - highPass->rgbPixels[i][j][k], 0, 255);
        }
      }
    }
  }

  delete lowPass;
  delete highPass;
}

void applyFilterHighboostStrategy(IMAGE* target, double alpha) {
  Kernel averageKernel;
  averageKernel.assign(5, std::vector<double>());
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      averageKernel[i].push_back(0.04);
    }
  }

  IMAGE* lowPass = new IMAGE(*target);
  applyFilterConvolutionStrategy(target, averageKernel);

  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
      if (target->rgbPixels == NULL){
        std::vector<int> tempPixel;
        uchar targetPixel = target->pixels[i][j];
        uchar lowpassPixel = lowPass->pixels[i][j];
        tempPixel.push_back(clip((double) targetPixel * alpha - lowpassPixel, 0, 255));
        target->pixels[i][j] = tempPixel[0];
      } else {
        std::vector<int> tempPixel;
        for (int k = 0; k < 3; k++){
          uchar targetrgb = target->rgbPixels[i][j][k];
          uchar lowpassrgb = lowPass->rgbPixels[i][j][k];
          tempPixel.push_back(clip((double) targetrgb * alpha - lowpassrgb, 0, 255));
          target->rgbPixels[i][j][k] = tempPixel[k];
        }
      }
    }
  }

  delete lowPass;
}

void applyFilterCannyStrategy(IMAGE* target) {
  Kernel kernelGaussian7 = loadKernel("gaussian7");
  Kernel kernelSobelX = loadKernel("sobelX");
  Kernel kernelSobelY = loadKernel("sobelY");

  IMAGE* smoothed = new IMAGE(*target);
  applyFilterConvolutionStrategy(smoothed, kernelGaussian7);

  IMAGE* sobelX = new IMAGE(*smoothed);
  applyFilterConvolutionStrategy(sobelX, kernelSobelX);

  IMAGE* sobelY = new IMAGE(*smoothed);
  applyFilterConvolutionStrategy(sobelY, kernelSobelY);

  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
      if (target->rgbPixels == NULL){
        int magnitudeX = sobelX->pixels[i][j] * sobelX->pixels[i][j];
        int magnitudeY = sobelY->pixels[i][j] * sobelY->pixels[i][j];
        if (magnitudeX + magnitudeY > 128 * 128){
          target->pixels[i][j] = 255;
        } else {
          target->pixels[i][j] = 0;
        }
      } else {
        int magnitudeX, magnitudeY;
        for (int k = 0; k < 3; k++){
          magnitudeX += sobelX->rgbPixels[i][j][k] * sobelX->rgbPixels[i][j][k];
          magnitudeY += sobelY->rgbPixels[i][j][k] * sobelY->rgbPixels[i][j][k];
        }
        magnitudeX = magnitudeX / 3;
        magnitudeY = magnitudeY / 3;

        if (magnitudeX + magnitudeY > 128 * 128){
          for (int k = 0; k < 3; k++){
            target->rgbPixels[i][j][k] = 255;
          }
        } else {
          for (int k = 0; k < 3; k++){
            target->rgbPixels[i][j][k] = 0;
          }
        }
      }
    }
  }

  delete smoothed;
  delete sobelX;
  delete sobelY;
}
