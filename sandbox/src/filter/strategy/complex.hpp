#ifndef FILTER_STRATEGY_COMPLEX_HPP
#define FILTER_STRATEGY_COMPLEX_HPP

#include "../../structure/image.hpp"

static void applyFilterUnsharpStrategy(IMAGE* target);

static void applyFilterHighboostStrategy(IMAGE* target, double alpha);

static void applyFilterCannyStrategy(IMAGE* target);
#endif
