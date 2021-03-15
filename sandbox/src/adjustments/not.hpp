#ifndef NOT_ADJUSTMENT
#define NOT_ADJUSTMENT

#include "base.hpp"

class NOTAdjustment : public Adjustment {
    public:
    static void apply(IMAGE* image);
};

#endif