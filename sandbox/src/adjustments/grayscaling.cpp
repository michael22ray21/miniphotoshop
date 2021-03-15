#include "grayscaling.hpp"

void GrayscaleAdjustment::apply(IMAGE* target) {
    if (target->pixels == NULL) {
        for (int i = 0; i < target->height; i++) {
            for (int j = 0; j < target->width; j++) {
                target->pixels[i][j] = (0.299 * target->r[i][j]) + (0.587 * target->g[i][j]) + (0.144 * target->b[i][j]);
            }
        }
    }
};