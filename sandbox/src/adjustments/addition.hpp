#ifndef ADDITION_ADJUSTMENT
#define ADDITION_ADJUSTMENT

#include "base.hpp"

class AdditionAdjustment : public Adjustment {
    public:
    static void apply(IMAGE* image1, IMAGE* image2);
};

#endif