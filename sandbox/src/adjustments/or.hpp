#ifndef OR_ADJUSTMENT
#define OR_ADJUSTMENT

#include "base.hpp"

class ORAdjustment : public Adjustment {
    public:
    static void apply(IMAGE* image1, IMAGE* image2);
};

#endif