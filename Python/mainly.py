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

def click_checkinn():
    call(["python", "checkin_gui_and_program.py"])
def click_list():
    call(["python", "listgui.py"])
def click_checkout():
    call(["python", "checkoutgui.py"])
def click_getinfo():
    call(["python","getinfoui.py"])    
def click_pickdrp():
    call(["python","Pick_and_Drop.py"])


class HOTEL_MANAGEMENT:
    def __init__(self):
        root = Tk()
       
       
        _bgcolor = '#ffffff' 
        _fgcolor = '#000000'  # X11 color: 'black'
        _compcolor = '#ffffff' # X11 color: 'white'
        _ana1color = '#ffffff' # X11 color: 'white'
        _ana2color = '#ffffff' # X11 color: 'white'
        font14 = "-family {Segoe UI} -size 15 -weight bold -slant "  \
            "roman -underline 0 -overstrike 0"
        font16 = "-family {Swis721 BlkCn BT} -size 40 -weight bold "  \
            "-slant roman -underline 0 -overstrike 0"
        font9 = "-family {Segoe UI} -size 9 -weight normal -slant "  \
            "roman -underline 0 -overstrike 0"

        root.geometry("963x749+540+110")
        root.title("HOTEL MANAGEMENT")
        root.configure(background="#ffffff")
        root.configure(highlightbackground="#ffffff")
        root.configure(highlightcolor="black")

        self.menubar = Menu(root,font=font9,bg=_bgcolor,fg=_fgcolor)
        root.configure(menu = self.menubar)

        self.Frame1 = Frame(root)
        self.Frame1.place(relx=0.02, rely=0.03, relheight=0.94, relwidth=0.96)
        self.Frame1.configure(relief=GROOVE)
        self.Frame1.configure(borderwidth="2")
        self.Frame1.configure(relief=GROOVE)
        self.Frame1.configure(width=925)

        self.Message6 = Message(self.Frame1)
        self.Message6.place(relx=0.09, rely=0.01, relheight=0.15, relwidth=0.86)
        self.Message6.configure(font=font16)
        self.Message6.configure(highlightcolor="black")
        self.Message6.configure(text='''WELCOME''')
        self.Message6.configure(width=791)

        self.Button2 = Button(self.Frame1)
        self.Button2.place(relx=0.18, rely=0.17, height=93, width=566)
        self.Button2.configure(font=font14)
        self.Button2.configure(highlightcolor="black")
        self.Button2.configure(text='''1.Check Inn''')
        self.Button2.configure(width=566)
        self.Button2.configure(command=click_checkinn)

        self.Button3 = Button(self.Frame1)
        self.Button3.place(relx=0.18, rely=0.30, height=93, width=566)
        self.Button3.configure(font=font14)
        self.Button3.configure(highlightcolor="black")
        self.Button3.configure(text='''2.Show Guest List''')
        self.Button3.configure(width=566)
        self.Button3.configure(command=click_list)

        self.Button4 = Button(self.Frame1)
        self.Button4.place(relx=0.18, rely=0.43, height=93, width=566)
        self.Button4.configure(font=font14)
        self.Button4.configure(highlightcolor="black")
        self.Button4.configure(text='''3.Check Out''')
        self.Button4.configure(width=566)
        self.Button4.configure(command=click_checkout)

        self.Button5 = Button(self.Frame1)
        self.Button5.place(relx=0.18, rely=0.56, height=93, width=566)
        self.Button5.configure(font=font14)
        self.Button5.configure(highlightcolor="black")
        self.Button5.configure(text='''4.Get Info About Any Guest''')
        self.Button5.configure(width=566)
        self.Button5.configure(command=click_getinfo)

        self.Button6 = Button(self.Frame1)
        self.Button6.place(relx=0.18, rely=0.69, height=93, width=566)
        self.Button6.configure(font=font14)
        self.Button6.configure(highlightcolor="black")
        self.Button6.configure(text='''5.Pick Up And Drop''')
        self.Button6.configure(width=566)
        self.Button6.configure(command=click_pickdrp)

        self.Button7 = Button(self.Frame1)
        self.Button7.place(relx=0.18, rely=0.82, height=93, width=566)
        #self.Button7.configure(activebackground="#d9d9d9")
        #self.Button7.configure(activeforeground="#000000")
        #self.Button7.configure(background="#d9d9d9")
        #self.Button7.configure(disabledforeground="#bfbfbf")
        self.Button7.configure(font=font14)
        #self.Button7.configure(foreground="#000000")
        #self.Button7.configure(highlightbackground="#d9d9d9")
        self.Button7.configure(highlightcolor="black")
        #self.Button7.configure(pady="0")
        self.Button7.configure(text='''6.Exit''')
        self.Button7.configure(width=566)
        self.Button7.configure(command=quit)
        
        #self.Button8.configure(self.Frame1)
        #self.Button8.place(relx=0.18, rely=0.93, height=50, width=600)
        #self.Button8.configure(activebackground="#d9d9d9")
        #self.Button8.configure(activeforebackground="#bfbfbf")
        #self.Button8.configure(background="#d9d9d9")
        #self.Button8.configure(disableforebackground="#bfbfbf")
        #self.Button8.configure(font="Times New Roman")
        #self.Button8.configure(foreground="#000000")
        #self.Button8.configure(highlightback)
                
        root.mainloop()

if __name__ == '__main__':
    GUUEST=HOTEL_MANAGEMENT()