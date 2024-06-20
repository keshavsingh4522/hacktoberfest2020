from tkinter import *

window=Tk()
window.geometry("700x500")

#---------------calculting function
def calculate():
    rice=e1.get()
    samosa=e2.get()
    those=e3.get()
    tea=e4.get()
    print(type(tea))

    total=((int(rice)*250)+(int(samosa)*50)+(int(those)*40)+(int(tea)*30))
    labelt=Label(window,text=total,font="times 28 bold")
    labelt.place(x=250,y=580)


#----------------------------Title-------------------
label=Label(window,text="Kobzzzzzz Hotel",font="times 28 bold")
label.place(x=300,y=20)



#--------------------------menu section------
label1=Label(window,text="Menu",font="times 22 bold")
label1.place(x=400,y=70)

label2=Label(window,text="Rice & curry              RS 250.00",font="times 18")
label2.place(x=350,y=120)

label3=Label(window,text="Samosa                         Rs50.00",font="times 18")
label3.place(x=350,y=150)

label4=Label(window,text="Those                          Rs40.00",font="times 18")
label4.place(x=350,y=180)

label5=Label(window,text="Tea                            Rs30.00",font="times 18")
label5.place(x=350,y=210)


#-------------------------------------biling section-------------------------------
label6=Label(window,text="Select the iterm",font="times 22 bold")
label6.place(x=100,y=70)

label6=Label(window,text="Rice & Curry",font="times 18")
label6.place(x=70,y=120)

e1=Entry(window)
e1.place(x=70,y=170)

label7=Label(window,text="Samosa",font="times 18")
label7.place(x=70,y=220)

e2=Entry(window)
e2.place(x=70,y=270)

label8=Label(window,text="Those",font="times 18")
label8.place(x=70,y=320)

e3=Entry(window)
e3.place(x=70,y=370)

label9=Label(window,text="Tea",font="times 18")
label9.place(x=70,y=430)

e4=Entry(window)
e4.place(x=70,y=480)

#---------------function button------------------
b1=Button(window,text="bill",width=20,command=calculate)
b1.place(x=250,y=550)





window.mainloop()