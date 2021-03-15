#ifndef FILTER_HPP
#define FILTER_HPP

#include "../structure/image.hpp"
#include "strategy/strategy.hpp"
#include "kernel.hpp"

class Filter {
private:
  FilterStrategyBase* strategy;
public:
  Filter(KernelType kernelType);

  /**
   * @method apply
   * @param {Image*} target of the filter
   */
  void apply(IMAGE* target);
};

#endif
