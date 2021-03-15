from distutils.core import setup, Extension
image_module = Extension(
    name='_image',
    sources=['image/clip.cpp', 'image/pixel.cpp'],
    swig_opts=['-c++']
)
setup (name = 'image',
   version = '0.1',
   author = "SWIG Docs",
   description = """Simple swig example from docs""",
   ext_modules = [image_module],
   headers=['image/clip.hpp', 'image/pixel.hpp'],
   py_modules = ["image"],
)