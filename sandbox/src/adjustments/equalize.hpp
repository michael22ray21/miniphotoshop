#ifndef HISTOGRAMEQUALIZE_ADJUSTMENT
#define HISTOGRAMEQUALIZE_ADJUSTMENT

#include "../structure/structure.hpp"
#include "base.hpp"

int** createHistogramDistribution(IMAGE* source);

class HistogramEqualizeAdjustment : public Adjustment {
public:
  /**
   * @method apply
   * @param {IMAGE*} target of the adjustment
   */
  static void apply(IMAGE* target);
};

class HistogramSpecificationAdjustment : public Adjustment {
public:
  /**
   * @method apply
   * @param {IMAGE*} target of the adjustment
   */
  static void apply(IMAGE* target, IMAGE* specification);
};

#endif
