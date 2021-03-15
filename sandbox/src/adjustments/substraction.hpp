#ifndef SUBSTRACTION_ADJUSTMENT
#define SUBSTRACTION_ADJUSTMENT

#include "base.hpp"

class SubstractionAdjustment : public Adjustment {
    public:
    static void apply(IMAGE* image1, IMAGE* image2);
};

#endif