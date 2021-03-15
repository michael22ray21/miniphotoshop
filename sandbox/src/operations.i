/* file : gfg.i */

/* name of module to use*/
%module reader
%{ 
	/* Every thing in this file is being copied in 
	wrapper file. We include the C header file necessary 
	to compile the interface */
	#include "operations/enhancements.hpp"
	#include "operations/equalizations.hpp"
	#include "filter/filter.hpp"
	#include "filter/kernel.hpp"
	#include "filter/strategy/complex.hpp"
	#include "filter/strategy/convolution.hpp"
	#include "filter/strategy/nonlinear.hpp"
	#include "filter/strategy/strategy.hpp"

	#include "utils/math.hpp"
	#include "utils/reader.hpp"
	#include "utils/loader.hpp"
	#include <fstream>

	/* variable declaration*/
	// double myvar; 
%} 

/* explicitly list functions and variables to be interfaced */
// double myvar; 
// long long int fact(long long int n1); 
// int my_mod(int m, int n); 

/* or if we want to interface all functions then we can simply 
include header file like this - 
%include "gfg.h" 
*/
%include "operations/enhancements.hpp"
%include "operations/equalizations.hpp"
%include "filter/filter.hpp"
%include "filter/kernel.hpp"
%include "filter/strategy/complex.hpp"
%include "filter/strategy/convolution.hpp"
%include "filter/strategy/nonlinear.hpp"
%include "filter/strategy/strategy.hpp"

%include "utils/math.hpp"
%include "utils/reader.hpp"
%include "utils/loader.hpp"
