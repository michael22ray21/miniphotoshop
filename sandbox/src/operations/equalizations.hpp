#ifndef HISTOGRAM_EQUALIZE_HPP
#define HISTOGRAM_EQUALIZE_HPP

#include "../structure/image.hpp"

int** createHistogramDistribution(IMAGE* source);

static void applyHistogramEqualize(IMAGE* target);
static void applyHistogramSpecification(IMAGE* target, IMAGE* specification);

#endif
