import tkinter as tk

class App:
    def __init__(self, window, window_title):
        self.window = window
        self.window.title(window_title)
        self.window.geometry('720x450')
        self.window.mainloop()

App(tk.Tk(), 'Sebuah window')