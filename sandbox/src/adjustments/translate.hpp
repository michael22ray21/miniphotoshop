#ifndef TRANSLATE_ADJUSTMENT
#define TRANSLATE_ADJUSTMENT

#include "base.hpp"

class TranslateAdjustment : public Adjustment {
public:
  static void apply(IMAGE* target, int m, int n);
};

#endif
