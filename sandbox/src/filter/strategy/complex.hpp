#ifndef FILTER_STRATEGY_COMPLEX_HPP
#define FILTER_STRATEGY_COMPLEX_HPP

#include "../../structure/image.hpp"

void applyFilterUnsharpStrategy(IMAGE* target);

void applyFilterHighboostStrategy(IMAGE* target, double alpha);

void applyFilterCannyStrategy(IMAGE* target);
#endif
