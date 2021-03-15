#ifndef INVERSE_ADJUSTMENT
#define INVERSE_ADJUSTMENT

#include "base.hpp"

class InverseAdjustment : public Adjustment {
    public:
    static void apply(IMAGE* target);
};

#endif