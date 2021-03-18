#include "filter.hpp"
#include "kernel.hpp"
#include "strategy/strategy.hpp"

// void applyFilter(IMAGE* target, KernelType kernelType, Kernel strategy) {
//   int group = checkKernelGroup(kernelType);

//   /** Convolutional kernel **/
//   if (0 < group && group < 4) {
//     std::string filename;

//     if (kernelType == AVERAGE) { filename = "average"; }
//     else if (kernelType == GAUSSIAN3) { filename = "gaussian3"; }
//     else if (kernelType == HIGH_A) { filename = "highA"; }
//     else if (kernelType == HIGH_B) { filename = "highB"; }
//     else if (kernelType == HIGH_C) { filename = "highC"; }
//     else if (kernelType == HIGH_D) { filename = "highD"; }
//     else if (kernelType == HIGH_E) { filename = "highE"; }
//     else if (kernelType == HIGH_F) { filename = "highF"; }
//     else if (kernelType == GRADIENT_X) { filename = "gradientX"; }
//     else if (kernelType == GRADIENT_Y) { filename = "gradientY"; }
//     else if (kernelType == DERIV2) { filename = "deriv2"; }
//     else if (kernelType == LAPLACE) { filename = "laplace"; }
//     else if (kernelType == LOG) { filename = "log"; }
//     else if (kernelType == SOBEL_X) { filename = "sobelX"; }
//     else if (kernelType == SOBEL_Y) { filename = "sobelY"; }
//     else if (kernelType == PREWITT_X) { filename = "prewittX"; }
//     else if (kernelType == PREWITT_Y) { filename = "prewittY"; }
//     else if (kernelType == ROBERTS_1) { filename = "roberts1"; }
//     else if (kernelType == ROBERTS_2) { filename = "roberts2"; }

//     Kernel kernel = loadKernel(filename);
//     applyFilterConvolutionStrategy(target, kernel);
//   }
//   /** Non linear kernel **/

//   else if (group == 0) {
//     switch (kernelType) {
//       case MEDIAN:
//         applyFilterMedianStrategy(target, 3);
//         break;
//       case MAX:
//         applyFilterMaxStrategy(target, 3);
//         break;
//       case MIN:
//         applyFilterMinStrategy(target, 3);
//         break;
//     }
//   }

//   /** Complex kernel **/
//   else if (group == 4) {
//     switch(kernelType) {
//       case UNSHARP:
//         applyFilterUnsharpStrategy(target);
//         break;
//       case HIGHBOOST:
//         applyFilterHighboostStrategy(target, 2.4);
//         break;
//       case CANNY:
//         applyFilterCannyStrategy(target);
//         break;
//     }
//   }
// }
