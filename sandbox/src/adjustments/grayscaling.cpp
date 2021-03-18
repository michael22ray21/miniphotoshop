#include "grayscaling.hpp"

void GrayscaleAdjustment::apply(IMAGE* target) {
    if (target->pixels == NULL) {
        target->pixels = (uchar**) malloc(target->height*sizeof(uchar*));
        for (int i = 0; i < target->height; i++) {
            for (int j = 0; j < target->width; j++) {
                target->pixels[i][j] = (0.299 * target->rgbPixels[i][j][0]) + (0.587 * target->rgbPixels[i][j][1]) + (0.144 * target->rgbPixels[i][j][2]);
            }
        }
        target->depth = 1;
        free(target->rgbPixels);
    }
};