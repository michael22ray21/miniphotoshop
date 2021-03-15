from tkinter import *
import image_processing as im  
from PIL import ImageTk,Image
import numpy as np
import ctypes


root = Tk()
ppm = im.PGM('../images/casablanca_small.pgm')
print(ppm.fileSize)
canvas = Canvas(root, width = ppm.width, height = ppm.height)  
canvas.pack()
ptr = int(ppm.pixels)
pixels = ctypes.c_ubyte * ppm.width * ppm.height
pixels = pixels.from_address(ptr)
pixel_array = np.asarray(pixels)
print(pixel_array)
img = ImageTk.PhotoImage(Image.fromarray(pixel_array,mode='L'))
canvas.create_image(20, 20, anchor=NW, image=img) 
root.mainloop() 