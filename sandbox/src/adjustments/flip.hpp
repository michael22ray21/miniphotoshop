#ifndef FLIP_ADJUSTMENT
#define FLIP_ADJUSTMENT

#include "base.hpp"

class FlipAdjustment : public Adjustment {
public:
  static void verticalFlip(IMAGE* target);
  static void horizontalFlip(IMAGE* target);
};

#endif
