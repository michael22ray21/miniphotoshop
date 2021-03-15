#ifndef AND_ADJUSTMENT
#define AND_ADJUSTMENT

#include "base.hpp"

class ANDAdjustment : public Adjustment {
    public:
    static void apply(IMAGE* image1, IMAGE* image2);
};

#endif