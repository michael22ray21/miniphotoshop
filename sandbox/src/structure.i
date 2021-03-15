/* file : gfg.i */

/* name of module to use*/
%module reader
%{ 
	/* Every thing in this file is being copied in 
	wrapper file. We include the C header file necessary 
	to compile the interface */
	#include "structure/image.hpp"
	#include "structure/bmp.hpp"
	#include "structure/pbm.hpp"
	#include "structure/ppm.hpp"
	#include "structure/pgm.hpp"
	#include "structure/raw.hpp"

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
%include "structure/image.hpp"
%include "structure/bmp.hpp"
%include "structure/pbm.hpp"
%include "structure/pgm.hpp"
%include "structure/ppm.hpp"
%include "structure/raw.hpp"

%include "utils/math.hpp"
%include "utils/reader.hpp"
%include "utils/loader.hpp"
