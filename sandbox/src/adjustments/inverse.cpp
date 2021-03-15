#include "inverse.hpp"

void InverseAdjustment::apply(IMAGE* target) {
    if (target->pixels != NULL) {
        for (int i = 0; i < target->height; i++) {
            for (int j = 0; j < target->width; j++) {
                target->pixels[i][j] = 255 - target->pixels[i][j];
            }
        }
    }
}