#ifndef ROTATE_ADJUSTMENT
#define ROTATE_ADJUSTMENT

#include "base.hpp"

class RotateAdjustment : public Adjustment {
public:
  static void rotate90CCW(IMAGE* target);
  static void rotate90CW(IMAGE* target);
};

#endif
