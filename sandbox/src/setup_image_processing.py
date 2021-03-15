# File : setup.py 

from distutils.core import setup, Extension 
#name of module 
name = "image_processing"

#version of module 
version = "1.0"

# specify the name of the extension and source files 
# required to compile this 
ext_modules = Extension(name='_image_processing',
sources=[
	"image_processing.i",
	"structure/image.cpp",
	"structure/bmp.cpp",
	"structure/pbm.cpp",
	"structure/pgm.cpp",
	"structure/ppm.cpp",
	"structure/raw.cpp",
	"utils/reader.cpp",
	"utils/loader.cpp",
	"utils/math.cpp"], 
swig_opts=['-c++']) 

setup(name=name, 
	version=version, 
	ext_modules=[ext_modules]) 
