import tkinter as tk
from PIL import ImageTk, Image  


class App:
    def __init__(self, window, window_title):
        self.window = window
        self.window.title(window_title)
        self.window.geometry('800x600')
        image1 = Image.open("../lena.bmp")
        tmp = ImageTk.PhotoImage(image1)

        label = tk.Label(image = tmp)
        label.image = tmp

        label.place(x=0, y=0)
        self.window.mainloop()

App(tk.Tk(), 'Sebuah window')
