from tkinter import *

root = Tk()
root.title("Calculator")
root.configure(background = "black")
root.iconbitmap('icon.ico')
#root.geometry("340x555")
root.minsize(340, 555)
root.maxsize(340, 555)


def click(event):
    global scvalue
    text = event.widget.cget("text")
    # print(text)
    if text == "=":
        if scvalue.get().isdigit():
            value = int(scvalue.get())
        else:
            value = eval(screen.get())
        scvalue.set(value)
        screen.update()

    elif text == "Clear":
        scvalue.set("")
        screen.update()

    else:
        scvalue.set(scvalue.get() + text)
        screen.update()    

scvalue = StringVar()
scvalue.set("")

screen = Entry(root, textvar = scvalue, font = "lucida 30 bold")
screen.pack(fill = X, pady = 10, padx = 10)



f = Frame(root, bg = "black")

b = Button(f, text = "Clear", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=10)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

b = Button(f, text = "%", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

f.pack()



f = Frame(root, bg = "black")

b = Button(f, text = "9", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

b = Button(f, text = "8", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

b = Button(f, text = "7", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

b = Button(f, text = "/", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

f.pack()



f = Frame(root, bg = "black")

b = Button(f, text = "6", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

b = Button(f, text = "5", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

b = Button(f, text = "4", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

b = Button(f, text = "*", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

f.pack()



f = Frame(root, bg = "black")

b = Button(f, text = "3", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

b = Button(f, text = "2", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

b = Button(f, text = "1", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

b = Button(f, text = "+", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

f.pack()



f = Frame(root, bg = "black")

b = Button(f, text = ".", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

b = Button(f, text = "0", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

b = Button(f, text = "=", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

b = Button(f, text = "-", bg="orange", padx = 10, pady = 10, font = "lucida 25 bold", width=2)
b.pack(side = LEFT, padx = 5, pady = 5)
b.bind("<Button-1>", click)

f.pack()


root.mainloop()