import os
from subprocess import call
import sys

try:
    from Tkinter import *
except ImportError:
    from tkinter import *

try:
    import ttk
    py3 = False
except ImportError:
    import tkinter.ttk as ttk
    py3 = True

class Pick_Drop:
    def __init__(self):
        root = Tk()
        root.geometry("963x749+540+110")
        root.title("HOTEL MANAGEMENT")
        root.configure(background="#d9d9d9")
        root.configure(highlightbackground="#d9d9d9")
        root.configure(highlightcolor="black")

        self.menubar = Menu(root,font="-family {Segoe UI} -size 9 -weight normal -slant "  \
            "roman -underline 0 -overstrike 0",bg="#000000",fg="#d9d9d9")
        root.configure(menu = self.menubar)

        self.Frame1 = Frame(root)
        self.Frame1.place(relx=0.02, rely=0.03, relheight=0.94, relwidth=0.96)
        self.Frame1.configure(relief=GROOVE)
        self.Frame1.configure(borderwidth="2")
        self.Frame1.configure(relief=GROOVE)
        self.Frame1.configure(background="#d9d9d9")
        self.Frame1.configure(highlightbackground="#d9d9d9")
        self.Frame1.configure(highlightcolor="black")
        self.Frame1.configure(width=925)

        self.Message6 = Message(self.Frame1)
        self.Message6.place(relx=0.09, rely=0.01, relheight=0.15, relwidth=0.86)
        self.Message6.configure(background="#d9d9d9")
        self.Message6.configure(font='gigi')
        self.Message6.configure(foreground="#000000")
        self.Message6.configure(highlightbackground="#d9d9d9")
        self.Message6.configure(highlightcolor="black")
        self.Message6.configure(text='''Pick Up And Drop''')
        self.Message6.configure(width=791)

        self.Label3 = Label(self.Frame1)
        self.Label3.place(relx=0.10, rely=0.17, height=47, width=289)
        self.Label3.configure(activebackground="#ffffff")
        self.Label3.configure(activeforeground="black")
        self.Label3.configure(background="#ffffff")
        self.Label3.configure(disabledforeground="#bfbfbf")
        self.Label3.configure(font='gigi')
        self.Label3.configure(foreground="#000000")
        self.Label3.configure(highlightbackground="#ffffff")
        self.Label3.configure(highlightcolor="black")
        self.Label3.configure(text='''Pick Up Point''')


        self.Entry5 = Entry(self.Frame1)
        self.addr = StringVar()
        self.Entry5.place(relx=0.47, rely=0.18,height=34, relwidth=0.43)
        self.Entry5.configure(background="white")
        self.Entry5.configure(disabledforeground="#bfbfbf")
        self.Entry5.configure(font='gigi')
        self.Entry5.configure(foreground="#000000")
        self.Entry5.configure(highlightbackground="#ffffff")
        self.Entry5.configure(highlightcolor="black")
        self.Entry5.configure(insertbackground="black")
        self.Entry5.configure(selectbackground="#e6e6e6")
        self.Entry5.configure(selectforeground="black")
        self.Entry5.configure(textvariable=self.addr)


        self.Label4 = Label(self.Frame1)
        self.Label4.place(relx=0.10, rely=0.30, height=47, width=289)
        self.Label4.configure(activebackground="#ffffff")
        self.Label4.configure(activeforeground="black")
        self.Label4.configure(background="#ffffff")
        self.Label4.configure(disabledforeground="#bfbfbf")
        self.Label4.configure(font='gigi')
        self.Label4.configure(foreground="#000000")
        self.Label4.configure(highlightbackground="#ffffff")
        self.Label4.configure(highlightcolor="black")
        self.Label4.configure(text='''Drop Point''')


        self.Entry6 = Entry(self.Frame1)
        self.addr = StringVar()
        self.Entry6.place(relx=0.47, rely=0.43,height=34, relwidth=0.43)
        self.Entry6.configure(background="white")
        self.Entry6.configure(disabledforeground="#bfbfbf")
        self.Entry6.configure(font='gigi')
        self.Entry6.configure(foreground="#000000")
        self.Entry6.configure(highlightbackground="#ffffff")
        self.Entry6.configure(highlightcolor="black")
        self.Entry6.configure(insertbackground="black")
        self.Entry6.configure(selectbackground="#e6e6e6")
        self.Entry6.configure(selectforeground="black")
        self.Entry6.configure(textvariable=self.addr)

        self.Label5 = Label(self.Frame1)
        self.Label5.place(relx=0.10, rely=0.43, height=47, width=289)
        self.Label5.configure(activebackground="#ffffff")
        self.Label5.configure(activeforeground="black")
        self.Label5.configure(background="#ffffff")
        self.Label5.configure(disabledforeground="#bfbfbf")
        self.Label5.configure(font='gigi')
        self.Label5.configure(foreground="#000000")
        self.Label5.configure(highlightbackground="#ffffff")
        self.Label5.configure(highlightcolor="black")
        self.Label5.configure(text='''Price ''')


        self.Entry7 = Entry(self.Frame1)
        self.addr = StringVar()
        self.Entry7.place(relx=0.47, rely=0.30,height=34, relwidth=0.43)
        self.Entry7.configure(background="white")
        self.Entry7.configure(disabledforeground="#bfbfbf")
        self.Entry7.configure(font='gigi')
        self.Entry7.configure(foreground="#000000")
        self.Entry7.configure(highlightbackground="#ffffff")
        self.Entry7.configure(highlightcolor="black")
        self.Entry7.configure(insertbackground="black")
        self.Entry7.configure(selectbackground="#e6e6e6")
        self.Entry7.configure(selectforeground="black")
        self.Entry7.configure(textvariable=self.addr)

        self.Button5 = Button(self.Frame1)
        self.Button5.place(relx=0.91, rely=0.43, height=33, width=43)
        self.Button5.configure(activebackground="#ffffff")
        self.Button5.configure(activeforeground="#000000")
        self.Button5.configure(background="#ffffff")
        self.Button5.configure(disabledforeground="#bfbfbf")
        self.Button5.configure(foreground="#000000")
        self.Button5.configure(highlightbackground="#ffffff")
        self.Button5.configure(highlightcolor="black")
        self.Button5.configure(pady="0")
        self.Button5.configure(text='''OK''')
        self.Button5.configure(command="")
        root.mainloop()

if __name__ == '__main__':
    GUUEST=Pick_Drop()