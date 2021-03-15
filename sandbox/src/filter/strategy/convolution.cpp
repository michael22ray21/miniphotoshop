#include <vector>
#include <cmath>
#include "convolution.hpp"
#include "../../utils/math.hpp"

void applyFilterConvolutionStrategy(IMAGE* target, Kernel kernel) {
  IMAGE* temp = new IMAGE(*target);
  for (int i = 0; i < target->height; i++) {
    for (int j = 0; j < target->width; j++) {
      std::vector<double> new_pixel;
      if (target->rgbPixels == NULL){
        new_pixel.push_back(0);
      } else {
        new_pixel.push_back(0);
        new_pixel.push_back(0);
        new_pixel.push_back(0);
      }
      
      int rowOffset = - (kernel.size() / 2);
      for (int i_k = 0; i_k < (int) kernel.size(); i_k++) {
        int colOffset = - (kernel[i_k].size() / 2);
        for (int j_k = 0; j_k < (int) kernel[i_k].size(); j_k++) {
          int i_target = std::max(0, std::min(target->height - 1, i + rowOffset + i_k));
          int j_target = std::max(0, std::min(target->width - 1, j + colOffset + j_k));

          if (target->rgbPixels == NULL){
            uchar px = temp->pixels[i_target][j_target];
            new_pixel[0] = clip((int) new_pixel[0] + px * kernel[i_k][j_k], 0, 255);            
          } else {
            for (int k = 0; k < 3; k++){
              uchar rgb = temp->rgbPixels[i_target][j_target][k];
              new_pixel[k] = clip((int) new_pixel[k] + rgb * kernel[i_k][j_k], 0, 255);
            }
          }
        }
      }
      if (target->pixels == NULL) {
          for (int k = 0; k < 3; k++){
            target->rgbPixels[i][j][k] = (uchar) clip(round(new_pixel[k]), 0, 255);
          }
      } else {
          target->pixels[i][j] = (uchar) clip(round(new_pixel[0]), 0, 255);
      }
    }
  }
  delete temp;
}
