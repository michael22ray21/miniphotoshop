#ifndef GRAYSCALE_ADJUSTMENT
#define GRAYSCALE_ADJUSTMENT

#include "base.hpp"

class GrayscaleAdjustment : public Adjustment {
    public:
    static void apply(IMAGE* target);
};

#endif