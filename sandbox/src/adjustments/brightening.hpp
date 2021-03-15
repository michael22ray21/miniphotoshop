#ifndef BRIGHTENING_ADJUSTMENT
#define BRIGHTENING_ADJUSTMENT

#include "base.hpp"

class BrighteningAdjustment : public Adjustment {
    public:
    static void apply(IMAGE* target, int b);
};

#endif