#ifndef ENHANCEMENT_H
#define ENHANCEMENT_H

#include "../structure/image.hpp"

static void brighten(IMAGE* target, double multiplier);
static void contrastStretch(IMAGE* target, int rMin, int rMax);
static void logTransform(IMAGE* target, double c);
static void inverseLog(IMAGE* target, double c);
static void power(IMAGE* target, double c);
static void graySlicing(IMAGE* target, int rMin, int rMax);
static void bitSlicing(IMAGE* target, int bit);


#endif // ENHANCEMENT_H

// brighten, constrastStretch, log, inverseLog, power, graySlicing, bitSlicing
