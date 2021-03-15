#ifndef FILTER_STRATEGY_MEDIAN_HPP
#define FILTER_STRATEGY_MEDIAN_HPP

#include "../../structure/image.hpp"

void applyFilterMedianStrategy(IMAGE* target, int size);

void applyFilterMaxStrategy(IMAGE* target, int size);

void applyFilterMinStrategy(IMAGE* target, int size);

#endif
