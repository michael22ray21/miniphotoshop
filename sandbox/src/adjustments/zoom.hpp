#ifndef ZOOM_ADJUSTMENT
#define ZOOM_ADJUSTMENT

#include "base.hpp"

class ZoomAdjustment : public Adjustment {
public:
  static void zoomOut(IMAGE* target);
  static void zoomIn(IMAGE* target);
};

#endif
