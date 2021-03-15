from tkinter import *
import image_processing as im  
from PIL import ImageTk,Image  
root = Tk()
ppm = im.PPM('../images/car-2.ppm')
print(ppm.fileSize)
canvas = Canvas(root, width = ppm.width, height = ppm.height)  
canvas.pack()  
img = ImageTk.PhotoImage(Image.open("../images/car-2.ppm"))  
canvas.create_image(20, 20, anchor=NW, image=img) 
root.mainloop() 