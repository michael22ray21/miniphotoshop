import time
import numpy as np
import tkinter as tk
import image_processing as im
from tkinter import filedialog
from PIL import Image, ImageTk

class App :
    def __init__(self, window, window_title, ori_image_source = '../images/lena.bmp') :
        self.window = window
        self.window.title(window_title)
        self.window.geometry('720x450')
        self.ori_image_source = ori_image_source

        self.open_image(self.ori_image_source)
        self.make_ori_image_canvas(self.ori_image.width, self.ori_image.height)

        # select file button
        self.ori_select_file = tk.Button(self.window, text = 'Select file', width = 8, command = self.open_ori_file)
        self.ori_select_file.place(x = self.ori_image.width//5 + 10, y = self.ori_image.height/2.5 + 55 + 121)

        # call the mainloop function to keep the window
        self.window.mainloop()

    def open_ori_file(self) :
        self.ori_file_name = filedialog.askopenfilename(initialdir = "/",title = "Select file", filetypes = (("Portable Bitmap Image File","*.pbm"),("Bitmap Image File","*.bmp"),("Portable Gray Map Image File","*.pgm"),("Portable Pixmap Image File","*.ppm"),("Raw Image Data File","*.raw")))
        self.open_image(str(self.ori_file_name))
        # update the image canvas
        self.make_ori_image_canvas(self.ori_image.height, self.ori_image.width)

    def make_ori_image_canvas(self, width, height) :
        # Create a canvas that can fit the above image source size
        self.ori_canvas_size = (int(np.ceil(width / 2.5)), int(np.ceil(height / 2.5)))
        self.ori_canvas = tk.Canvas(self.window, width = self.ori_canvas_size[0], height = self.ori_canvas_size[1])
        self.ori_canvas.place(x = 50, y = 121)

    def open_image(self, filename) :
        # print(filename)
        if filename.endswith('.pbm') :
            self.ori_image = im.PBM(filename)
        elif filename.endswith('.bmp') :
            self.ori_image = im.BMP(filename)
        elif filename.endswith('.pgm') :
            self.ori_image = im.PGM(filename)
        elif filename.endswith('.ppm') :
            self.ori_image = im.PPM(filename)
        elif filename.endswith('.raw') :
            self.ori_image = im.RAW(filename)

App(tk.Tk(), "Miniphotoshop")