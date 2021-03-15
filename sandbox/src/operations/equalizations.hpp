#ifndef PROTOSHOP_ADJUSTMENT_HISTOGRAMEQUALIZE
#define PROTOSHOP_ADJUSTMENT_HISTOGRAMEQUALIZE

#include "../structure/image.hpp"

int** createHistogramDistribution(IMAGE* source);

static void applyHistogramEqualize(IMAGE* target);
static void applyHistogramSpecification(IMAGE* target, IMAGE* specification);

#endif
