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
      if (highPass->r == NULL){
        highPass->pixels[i][j] = clip((int) target->pixels[i][j] - lowPass->pixels[i][j], 0, 255);
      }else{
        highPass->r[i][j] = clip((int) target->r[i][j] - lowPass->r[i][j], 0, 255);
        highPass->g[i][j] = clip((int) target->g[i][j] - lowPass->g[i][j], 0, 255);
        highPass->b[i][j] = clip((int) target->b[i][j] - lowPass->b[i][j], 0, 255);
      }
    }
  }

  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
      if (highPass->r == NULL){
        target->pixels[i][j] = clip((int) target->pixels[i][j] + highPass->pixels[i][j], 0, 255);
      }else{
        target->r[i][j] = clip((int) target->r[i][j] - highPass->r[i][j], 0, 255);
        target->g[i][j] = clip((int) target->g[i][j] - highPass->g[i][j], 0, 255);
        target->b[i][j] = clip((int) target->b[i][j] - highPass->b[i][j], 0, 255);
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
      if (target->r == NULL){
        std::vector<int> tempPixel;
        uchar targetPixel = target->pixels[i][j];
        uchar lowpassPixel = lowPass->pixels[i][j];
        tempPixel.push_back(clip((double) targetPixel * alpha - lowpassPixel, 0, 255));
        target->pixels[i][j] = tempPixel[0];
      } else {
        std::vector<int> tempPixel;
        uchar targetr = target->r[i][j];
        uchar targetg = target->g[i][j];
        uchar targetb = target->b[i][j];

        uchar lowpassr = lowPass->r[i][j];
        uchar lowpassg = lowPass->g[i][j];
        uchar lowpassb = lowPass->b[i][j];

        tempPixel.push_back(clip((double) targetr * alpha - lowpassr, 0, 255)); 
        tempPixel.push_back(clip((double) targetg * alpha - lowpassg, 0, 255)); 
        tempPixel.push_back(clip((double) targetb * alpha - lowpassb, 0, 255));

        target->r[i][j] = tempPixel[0];
        target->g[i][j] = tempPixel[1];
        target->b[i][j] = tempPixel[2];
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
      if (target->r == NULL){
        int magnitudeX = sobelX->pixels[i][j] * sobelX->pixels[i][j];
        int magnitudeY = sobelY->pixels[i][j] * sobelY->pixels[i][j];
        if (magnitudeX + magnitudeY > 128 * 128){
          target->pixels[i][j] = 255;
        } else {
          target->pixels[i][j] = 0;
        }
      } else {
        int magnitudeX = 
          (sobelX->r[i][j] * sobelX->r[i][j] + 
          sobelX->g[i][j] * sobelX->g[i][j] + 
          sobelX->b[i][j] * sobelX->b[i][j]) / 3;

        int magnitudeY = 
          (sobelY->r[i][j] * sobelY->r[i][j] + 
          sobelY->g[i][j] * sobelY->g[i][j] + 
          sobelY->b[i][j] * sobelY->b[i][j]) / 3;

        if (magnitudeX + magnitudeY > 128 * 128){
          target->r[i][j] = 255;
          target->g[i][j] = 255;
          target->b[i][j] = 255;
        } else {
          target->r[i][j] = 0;
          target->g[i][j] = 0;
          target->b[i][j] = 0;
        }
      }
    }
  }

  delete smoothed;
  delete sobelX;
  delete sobelY;
}
