#ifndef XOR_ADJUSTMENT
#define XOR_ADJUSTMENT

#include "base.hpp"

class XORAdjustment : public Adjustment {
    public:
    static void apply(IMAGE* image1, IMAGE* image2);
};

#endif