#ifndef HISTOGRAM_EQUALIZE_HPP
#define HISTOGRAM_EQUALIZE_HPP

#include "../structure/image.hpp"

int** createHistogramDistribution(IMAGE* source);

void applyHistogramEqualization(IMAGE* target);
void applyHistogramSpecification(IMAGE* target, IMAGE* specification);

#endif
