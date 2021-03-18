from tkinter import *
import image_processing as im  
from PIL import ImageTk,Image
import numpy as np
import ctypes


root = Tk()
ppm = im.RAW('../images/sample.raw')
print(ppm.fileSize)
canvas = Canvas(root, width = ppm.width, height = ppm.height)  
canvas.pack()
# print(dir(im))
# kernel = im.loadKernel('filter/kernels/average.txt')

print(ppm.bitCount)
# im.createHistogramDistribution
ptr = int(im.createHistogramDistribution(ppm))
print(ppm.depth)
depth = int(ppm.depth)
pixels = ctypes.c_int * depth * 256
pixels = pixels.from_address(ptr)
pixel_array = np.asarray(pixels)
print(pixel_array)

# hist = im.createHistogramDistribution(ppm)
# print(hist)
# ptr2 = int(hist)
# histpixels = ctypes.c_int32 * 256 * 256
# histpixels = histpixels.from_address(ptr2)
# pixel_hist = np.asarray(histpixels)
# print(pixel_hist)

# # im.applyFilterConvolutionStrategy(ppm, kernel)
# im.bitSlicing(ppm, 4)

# ptr = int(ppm.pixels)
# pixels = ctypes.c_ubyte * ppm.width * ppm.height
# pixels = pixels.from_address(ptr)
# pixel_array = np.asarray(pixels)
# print(pixel_array)
img = ImageTk.PhotoImage(Image.fromarray(pixel_array,mode='L'))
canvas.create_image(20, 20, anchor=NW, image=img) 
root.mainloop() 