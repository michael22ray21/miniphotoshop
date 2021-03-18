#ifndef ENHANCEMENT_H
#define ENHANCEMENT_H

#include "../structure/image.hpp"

void brightenMul(IMAGE* target, double multiplier);
void brightenAdd(IMAGE* target, double multiplier);
void contrastStretch(IMAGE* target, int rMin, int rMax);
void logTransform(IMAGE* target, double c);
void inverseLog(IMAGE* target, double c);
void power(IMAGE* target, double c);
void graySlicing(IMAGE* target, int rMin, int rMax);
void bitSlicing(IMAGE* target, int bit);


#endif // ENHANCEMENT_H

// brighten, constrastStretch, log, inverseLog, power, graySlicing, bitSlicing
