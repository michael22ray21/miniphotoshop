#ifndef FILTER_STRATEGY_CONVOLUTION_HPP
#define FILTER_STRATEGY_CONVOLUTION_HPP

#include "../../structure/image.hpp"
#include "../kernel.hpp"

void applyFilterConvolutionStrategy(IMAGE* target, std::vector<std::vector<double>> kernel);

#endif
