from tkinter import *
from tkinter import messagebox
from tkinter.ttk import Combobox
import datetime
def cromad():
    root1=Toplevel()
    def c0():
        bill=Frame(root1,width=400,height=330)
        bill.place(x=590,y=50)
        billm=Label(bill,text='Bill',font='Aerial 20')
        billm.place(x=180,y=0)
        dt='Date Time  '+str(datetime.datetime.now())
        dt1=Label(bill,text=dt,font='Aerial 15')
        dt1.place(x=0,y=40)
        if i1.get()==1:
            e1=entry1.get()
            r1=10000*(int(e1))
            bill1=Label(bill,text='Google Home            '+'Rs.'+str(r1),font='Aerial 12')
            bill1.place(x=0,y=70)
        else :
            r1=0
        if i2.get()==1:
            e2=entry2.get()
            r2=5000*(int(e2))
            bill2=Label(bill,text='Boat rockerz 1100    '+'Rs.'+str(r2),font='Aerial 12')
            bill2.place(x=0,y=90)
        else :
            r2=0
        if i3.get()==1:
            e3=entry3.get()
            r3=14000*(int(e3))
            bill3=Label(bill,text='Lenovo Zuk z2+       '+'Rs.'+str(r3),font='Aerial 12')
            bill3.place(x=0,y=110)
        else :
            r3=0
        if i4.get()==1:
            e4=entry4.get()
            r4=100500*int(e4)
            bill4=Label(bill,text='iphone 11                  '+'Rs.'+str(r4),font='Aerial 12')
            bill4.place(x=0,y=130)
        else :
            r4=0
        if i5.get()==1:
            e5=entry5.get()
            r5=18000*int(e5)
            bill5=Label(bill,text='vivo v11 pro              '+'Rs.'+str(r5),font='Aerial 12')
            bill5.place(x=0,y=150)
        else :
            r5=0
        total=Label(bill,text='Total                              '+'Rs.'+str(r1+r2+r3+r4+r5),font='Aerial 12')
        total.place(x=0,y=190)
        thank=Label(bill,text='Thank You. Your order will be'+'\n'+'delivered within 4-5 working days.',font='Aerial 15')
        thank.place(x=50,y=210)
        quit1=Button(root1,text='Exit',command=root1.destroy,font='Times 12')
        quit1.place(x=770,y=390)
    def checkcroma1():
        txt=StringVar()
        global entry1
        q1=Label(root1,text='quantity',bg='light blue',font='miriam 15',fg='red')
        q1.place(x=350,y=50)
        entry1=Entry(root1)
        entry1.place(x=420,y=55)
    def checkcroma2():
        global entry2
        txt=StringVar()
        q2=Label(root1,text='quantity',bg='light blue',font='miriam 15',fg='red')
        q2.place(x=350,y=80)
        entry2=Entry(root1)
        entry2.place(x=420,y=85)
    def checkcroma3():
        global entry3
        txt=StringVar()
        q3=Label(root1,text='quantity',bg='light blue',font='miriam 15',fg='red')
        q3.place(x=350,y=110)
        entry3=Entry(root1)
        entry3.place(x=420,y=115)
    def checkcroma4():
        global entry4
        txt=StringVar()
        q4=Label(root1,text='quantity',bg='light blue',font='miriam 15',fg='red')
        q4.place(x=350,y=140)
        entry4=Entry(root1)
        entry4.place(x=420,y=145)
    def checkcroma5():
        global entry5
        txt=StringVar()
        q5=Label(root1,text='quantity',bg='light blue',font='miriam 15',fg='red')
        q5.place(x=350,y=170)
        entry5=Entry(root1)
        entry5.place(x=420,y=175)
    root1.configure(bg='light blue')
    root1.geometry('900x600+150+150')
    root1.title('Croma')
    cm=Label(root1,text='Welcome To Croma',font='Aerial 30',bg='light blue')
    cm.pack()
    i1=IntVar(root1)
    c1=Checkbutton(root1,text='Google Home            Rs.10000',font='courier 12',bg='light blue',fg='blue',command=checkcroma1,variable=i1)
    c1.place(x=0,y=50)
    i2=IntVar(root1)
    c2=Checkbutton(root1,text='Boat rockerz 1100      Rs.5000',font='courier 12',bg='light blue',fg='blue',command=checkcroma2,variable=i2)
    c2.place(x=0,y=80)
    i3=IntVar(root1)
    c3=Checkbutton(root1,text='Lenovo Zuk z2+         Rs.14000',font='courier 12',bg='light blue',fg='blue',command=checkcroma3,variable=i3)
    c3.place(x=0,y=110)
    i4=IntVar(root1)
    c4=Checkbutton(root1,text='iphone 11              Rs.100500',font='courier 12',bg='light blue',fg='blue',command=checkcroma4,variable=i4)
    c4.place(x=0,y=140)
    i5=IntVar(root1)
    c5=Checkbutton(root1,text='vivo v11 pro           Rs.18000',font='courier 12',bg='light blue',fg='blue',command=checkcroma5,variable=i5)
    c5.place(x=0,y=170)
    lastb=Button(root1,text='Next',font='courier',fg='blue',command=c0)
    lastb.place(x=100,y=200)
    disc=Canvas(root1,width=225,height=225,bg='light blue')
    disc.place(x=30,y=250)
    disc1=PhotoImage(file='./disc.png')
    disc.create_image(0,0,image=disc1,anchor=NW)
    root1.mainloop()
def wranglerd():
    root2=Toplevel()
    def billw1():
        billw=Canvas(root2,width=400,height=350)
        billw.place(x=400,y=60)
        billl=Label(billw,text='WRANGLER',font='Aerial 20')
        billl.place(x=135,y=5)
        titlew=Label(billw,text='Product - Rate - Qty - Price',font='Aerial 15')
        titlew.place(x=5,y=40)
        l1=l.curselection()
        s=70
        for i in l1:
            product=Label(billw,text=l.get(i),font='Aerial 12')
            product.place(x=5,y=s)
            s+=20
        l2=[]
        for i in l1:
            l2.append(i)
        for i in l2:
            if l2.index(i)==0:
                x1=225
                y1=70
            if l2.index(i)==1:
                x1=225
                y1=90
            if l2.index(i)==2:
                x1=225
                y1=110
            if l2.index(i)==3:
                x1=225
                y1=130
            if l2.index(i)==4:
                x1=225
                y1=150
            if i==0:
                qty1=Entry(billw,width=6)
                qty1.place(x=x1,y=y1)
            if i==1:
                qty2=Entry(billw,width=6)
                qty2.place(x=x1,y=y1)
            if i==2:
                qty3=Entry(billw,width=6)
                qty3.place(x=x1,y=y1)
            if i==3:
                qty4=Entry(billw,width=6)
                qty4.place(x=x1,y=y1)
            if i==4:
                qty5=Entry(billw,width=6)
                qty5.place(x=x1,y=y1)

        def billw2():
            for i in l2:
                if l2.index(i)==0:
                    x1=255
                    y1=70
                if l2.index(i)==1:
                    x1=255
                    y1=90
                if l2.index(i)==2:
                    x1=255
                    y1=110
                if l2.index(i)==3:
                    x1=255
                    y1=130
                if l2.index(i)==4:
                    x1=255
                    y1=150
                if i==0:
                    price1=2500*int(qty1.get())
                    p1=Label(billw,text='RS.'+str(price1))
                    p1.place(x=x1,y=y1)
                if i==1:
                    price2=3000*int(qty2.get())
                    p2=Label(billw,text='RS.'+str(price2))
                    p2.place(x=x1,y=y1)
                if i==2:
                    price3=3500*int(qty3.get())
                    p3=Label(billw,text='RS.'+str(price3))
                    p3.place(x=x1,y=y1)
                if i==3:
                    price4=2000*int(qty4.get())
                    p4=Label(billw,text='RS.'+str(price4))
                    p4.place(x=x1,y=y1)
                if i==4:
                    price5=2000*int(qty5.get())
                    p5=Label(billw,text='RS.'+str(price5))
                    p5.place(x=x1,y=y1)
            total=0
            for i in l2:
                if i==0:
                    price1=2500*int(qty1.get())
                    total+=price1
                else :
                    price1=0
                    total+=price1
                if i==1:
                    price2=3000*int(qty2.get())
                    total+=price2
                else :
                    price2=0
                    total+=price2
                if i==2:
                    price3=3500*int(qty3.get())
                    total+=price3
                else :
                    price3=0
                    total+=price3
                if i==3:
                    price4=2000*int(qty4.get())
                    total+=price4
                else :
                    price4=0
                    total+=price4
                if i==4:
                    price5=2000*int(qty5.get())
                    total+=price5
                else :
                    price5=0
                    total+=price5
            totalw=Label(billw,text='Total'+'\t'+'RS.'+str(total),font='Aerial 12')
            totalw.place(x=20,y=180)
            thank=Label(billw,text='Thank you. Your order will be'+'\n'+'delivered within 2-3 working days.',font='Aerial 15')
            thank.place(x=50,y=200)
        billn=Button(billw,text='continue',command=billw2)
        billn.place(x=20,y=270)
        quit2=Button(billw,text='Exit',font='Times 12',command=root2.destroy)
        quit2.place(x=350,y=270)
    root2.configure(bg='pink')
    root2.geometry('900x600+150+150')
    root2.title('Wrangler')
    wm=Label(root2,text='Welcome To Wrangler',font='century 30',bg='pink')
    l=Listbox(root2,width=30,height=7,font='courier 12',selectmode='multiple')
    l.place(x=40,y=60)
    l.insert(0,'Wrangler Tshirt - RS.2500')
    l.insert(1,'Wrangler Formals - RS.3000')
    l.insert(2,'Wrangler Jeans - RS.3500')
    l.insert(3,'Formal pant - RS.2000')
    l.insert(4,'Tracksuit - RS.2000')
    wm.pack()
    bw=Button(root2,text='Next',font='courier',fg='blue',command=billw1)
    bw.place(x=140,y=200)
    root2.mainloop()
def mc():
    def billt():
        billw=Canvas(mcw,width=400,height=350)
        billw.place(x=460,y=120)
        billl=Label(billw,text="McDonald's",font='Aerial 20')
        billl.place(x=135,y=5)
        titlew=Label(billw,text='Product - Rate - Qty - Price',font='Aerial 15')
        titlew.place(x=5,y=40)
        l1=lb.curselection()
        s=70
        for i in l1:
            product=Label(billw,text=lb.get(i),font='Aerial 12')
            product.place(x=5,y=s)
            s+=20
        l2=[]
        for i in l1:
            l2.append(i)
        for i in l2:
            if l2.index(i)==0:
                x1=225
                y1=70
            if l2.index(i)==1:
                x1=225
                y1=90
            if l2.index(i)==2:
                x1=225
                y1=110
            if l2.index(i)==3:
                x1=225
                y1=130
            if l2.index(i)==4:
                x1=225
                y1=150
            if l2.index(i)==5:
                x1=225
                y1=170
            if i==0:
                qty1=Entry(billw,width=6)
                qty1.place(x=x1,y=y1)
            if i==1:
                qty2=Entry(billw,width=6)
                qty2.place(x=x1,y=y1)
            if i==2:
                qty3=Entry(billw,width=6)
                qty3.place(x=x1,y=y1)
            if i==3:
                qty4=Entry(billw,width=6)
                qty4.place(x=x1,y=y1)
            if i==4:
                qty5=Entry(billw,width=6)
                qty5.place(x=x1,y=y1)
            if i==5:
                qty6=Entry(billw,width=6)
                qty6.place(x=x1,y=y1)
        def billw2():
            for i in l2:
                if l2.index(i)==0:
                    x1=255
                    y1=70
                if l2.index(i)==1:
                    x1=255
                    y1=90
                if l2.index(i)==2:
                    x1=255
                    y1=110
                if l2.index(i)==3:
                    x1=255
                    y1=130
                if l2.index(i)==4:
                    x1=255
                    y1=150
                if l2.index(i)==5:
                    x1=255
                    y1=170
                if i==0:
                    price1=289*int(qty1.get())
                    p1=Label(billw,text='RS.'+str(price1))
                    p1.place(x=x1,y=y1)
                if i==1:
                    price2=308*int(qty2.get())
                    p2=Label(billw,text='RS.'+str(price2))
                    p2.place(x=x1,y=y1)
                if i==2:
                    price3=148*int(qty3.get())
                    p3=Label(billw,text='RS.'+str(price3))
                    p3.place(x=x1,y=y1)
                if i==3:
                    price4=185*int(qty4.get())
                    p4=Label(billw,text='RS.'+str(price4))
                    p4.place(x=x1,y=y1)
                if i==4:
                    price5=97*int(qty5.get())
                    p5=Label(billw,text='RS.'+str(price5))
                    p5.place(x=x1,y=y1)
                if i==5:
                    price6=197*int(qty6.get())
                    p6=Label(billw,text='RS.'+str(price6))
                    p6.place(x=x1,y=y1)
            total=0
            for i in l2:
                if i==0:
                    price1=289*int(qty1.get())
                    total+=price1
                else :
                    price1=0
                    total+=price1
                if i==1:
                    price2=308*int(qty2.get())
                    total+=price2
                else :
                    price2=0
                    total+=price2
                if i==2:
                    price3=148*int(qty3.get())
                    total+=price3
                else :
                    price3=0
                    total+=price3
                if i==3:
                    price4=185*int(qty4.get())
                    total+=price4
                else :
                    price4=0
                    total+=price4
                if i==4:
                    price5=97*int(qty5.get())
                    total+=price5
                else :
                    price5=0
                    total+=price5
                if i==5:
                    price6=197*int(qty6.get())
                    total+=price6
                else :
                    price6=0
                    total+=price6
            totalw=Label(billw,text='Total'+'\t'+'RS.'+str(total),font='Aerial 12')
            totalw.place(x=20,y=210)
            thank=Label(billw,text='Thank you. Your order will'+'\n'+'be delivered within 1hour!!',font='Aerial 15')
            thank.place(x=50,y=230)
        billn=Button(billw,text='continue',command=billw2)
        billn.place(x=20,y=300)
        quit2=Button(billw,text='Exit',font='Times 12',command=mcw.destroy)
        quit2.place(x=350,y=300)
    mcw=Toplevel()
    mcw.configure(bg='gold2')
    mcw.geometry('900x600+150+150')
    mcw.title("McDonald's")
    mct=Label(mcw,text="Welcome To McDonald's",font='century 30',bg='gold2')
    mct.pack()
    menu=Label(mcw,text='Menu',font='Calibiri 30',bg='gold2')
    menu.place(x=60,y=60)
    lb=Listbox(mcw,width=35,height=4,font='Calibiri 14',selectmode='multiple')
    lb.insert(0,'Big spicy wrap- Rs.289')
    lb.insert(1,'Maharaja Mac- Rs.308')
    lb.insert(2,'McAloo tikki- Rs.148')
    lb.insert(3,'Piri Piri + nuggets- Rs.185')
    lb.insert(4,'McFlurry Oreo- Rs.97')
    lb.insert(5,'McVeggie- Rs.197')
    lb.place(x=60,y=120)
    lw=Button(mcw,text='Next',font='courier',fg='blue',command=billt)
    lw.place(x=160,y=240)
    mcw.mainloop()
def mains(x):
    root=Toplevel()
    root.title('Desidime')
    root.configure(bg='yellow')
    root.geometry('600x900+150+10')
    welcome=Label(root,text='Welcome',font='century 50',bg='yellow')
    welcome.place(x=540,y=5)
    canvas=Canvas(root,width=600,height=230,bg='violet')
    canvas.place(x=30,y=100)
    f1=Label(canvas,text='Electronics',font='century 25',bg='orange',relief='solid')
    f1.place(x=230,y=5)
    croma=PhotoImage(file='./croma.png')
    canvas.create_image(200,60,image=croma,anchor=NW)
    croma1=Button(canvas,text='Tap to enter',font='comic 15',fg='red',command=cromad)
    croma1.place(x=240,y=180)
    canvas2=Canvas(root,width=600,height=230,bg='light green')
    canvas2.place(x=700,y=100)
    f2=Label(canvas2,text='Clothing',font='century 25',bg='orange',relief='solid')
    f2.place(x=240,y=5)
    wrangler=PhotoImage(file='./wrangler.png')
    canvas2.create_image(200,60,image=wrangler,anchor=NW)
    wrangler1=Button(canvas2,text='Tap to enter',font='comic 15',fg='red',command=wranglerd)
    wrangler1.place(x=240,y=155)
    canvas3=Canvas(root,width=600,height=280,bg='dodgerblue2')
    canvas3.place(x=350,y=350)
    f3=Label(canvas3,text='Food delivery',font='century 25',bg='orange',relief='solid')
    f3.place(x=200,y=5)
    mcd=PhotoImage(file='./mcd.png')
    canvas3.create_image(200,60,image=mcd,anchor=NW)
    mcd1=Button(canvas3,text='Tap to enter',font='comic 15',fg='red',command=mc)
    mcd1.place(x=240,y=230)
    nm=Label(root,text=x,font='century 50',bg='yellow')
    nm.place(x=840,y=5)
    root.mainloop()
def login():
    def login1():
        f=open('profile.txt','r')
        u=usn1.get()
        p=pas1.get()
        a=f.readlines()
        for i in range(0,len(a),4):
            if u==a[i][:-1]:
                if p==a[i+1][:-1]:
                    mains(u)
                    Label(log,bg='seagreen2').place(height=35,width=2000,x=75,y=400)
                else :
                    err=Label(log,text='Password does not match',font='Georgio 14',fg='red',bg='seagreen2')
                    err.place(x=80,y=400)
        f.close()
    log=Toplevel()
    log.title('Login')
    log.geometry('600x600+100+20')
    log.configure(bg='seagreen2')
    lm=Label(log,text='LOGIN',font='Calibiri 24',bg='seagreen2')
    lm.place(x=260,y=50)
    usn=Label(log,text='Username : ',font='Georgia 18',bg='seagreen2')
    usn.place(x=80,y=150)
    usn1=Entry(log,font='verdana 15')
    usn1.place(height=30,width=200,x=230,y=155)
    pas=Label(log,text='Password : ',font='Georgio 18',bg='seagreen2')
    pas.place(x=80,y=220)
    pas1=Entry(log,show='*',font='verdana 15')
    pas1.place(height=30,width=200,x=230,y=225)
    lgn=Button(log,text='Login',font='Geogrio 18',bg='peach puff',command=login1)
    lgn.place(x=260,y=300)
    log.mainloop()
def signup():
    def sign1():
        f=open('profile.txt','a')
        fr=open('profile.txt','r')
        fr1=fr.readlines()
        u=uname1.get()
        p=passw1.get()
        ap=0
        for i in range(0,len(fr1),4):
            op=fr1[i]
            if op[0:-1]==u :
                Label(sup,text='Username already taken',font='Gerogio 14',fg='red',bg='lemon chiffon').place(x=52,y=390)
                ap=1
        lq=0
        for i in range(2,len(fr1),4):
            em=fr1[i]
            if em[0:-1]==str(email1.get()) :
                Label(sup,text='Email Id already registered',font='Gerogio 14',fg='red',bg='lemon chiffon').place(x=52,y=390)
                lq=1
        pq=0
        for i in range(3,len(fr1),4):
            pn=fr1[i]
            if pn[0:-1]==str(phn1.get()) :
                Label(sup,text='Phone No. already registered',font='Gerogio 14',fg='red',bg='lemon chiffon').place(x=52,y=390)
                pq=1
        if '@' in str(email1.get()):
            em=str(email1.get())
            new=Label(sup,bg='lemon chiffon')
            new.place(x=50,y=390)
        else :
            erro=Label(sup,text='Enter a valid email id         ',font='Georgio 14',fg='red',bg='lemon chiffon')
            erro.place(x=52,y=390)
            
        if (phn1.get()).isdigit() and len(str(phn1.get()))==10:
            pn=int(phn1.get())
            new=Label(sup,bg='lemon chiffon')
            new.place(x=50,y=390)
        else :
            err=Label(sup,text='Enter a valid phone no.',font='Georgio 14',fg='red',bg='lemon chiffon')
            err.place(x=52,y=390)
        if '@' in str(email1.get()) and (phn1.get()).isdigit() and len(str(phn1.get()))==10 and ap==0 and pq==0 and lq==0:
            f.write(u+'\n')
            f.write(p+'\n')
            f.write(em+'\n')
            f.write(str(pn)+'\n')
            suc=Label(sup,text='Succesfully Signed In',font='Geogrio 18',fg='forest green',bg='lemon chiffon')
            suc.place(x=100,y=420)
            gb=Button(sup,text='Back',command=sup.destroy,font='Georgio 16',bg='peach puff')
            gb.place(x=380,y=420)
            erase=Label(sup,text='  '*30,font='Georgio 16',fg='forest green',bg='lemon chiffon')
            erase.place(x=50,y=390)
        f.close()
    def sh1():
        Label(sup,text=str(passw1.get()),font='verdana 15',fg='white',bg='light blue').place(x=200,y=195)
    def hd1():
        Label(sup,bg='lemon chiffon').place(height=35,width=10000,x=198,y=195)
    sup=Toplevel()
    sup.title('Sign Up')
    sup.geometry('600x600+100+20')
    sup.configure(bg='lemon chiffon')
    sm=Label(sup,text='SIGN UP',font='Calibiri 24',bg='lemon chiffon')
    sm.place(x=260,y=20)
    uname=Label(sup,text='Username : ',font='Georgia 18',bg='lemon chiffon')
    uname.place(x=50,y=100)
    uname1=Entry(sup,font='verdana 15')
    uname1.place(height=30,width=200,x=200,y=105)
    passw=Label(sup,text='Password : ',font='Georgio 18',bg='lemon chiffon')
    passw.place(x=50,y=150)
    passw1=Entry(sup,show='*',font='verdana 15')
    passw1.place(height=30,width=200,x=200,y=155)
    sh=Button(sup,text='show',font='Georgio 14',fg='red',bg='lemon chiffon',command=sh1)
    sh.place(x=405,y=155)
    hd=Button(sup,text='hide',font='Georgio 14',fg='red',bg='lemon chiffon',command=hd1)
    hd.place(x=475,y=155)
    email=Label(sup,text='Email Id : ',font='Georgio 18',bg='lemon chiffon')
    email.place(x=50,y=240)
    email1=Entry(sup,font='verdana 15')
    email1.place(height=30,width=300,x=200,y=240)
    phn=Label(sup,text='Phone No : ',font='Georgio 18',bg='lemon chiffon')
    phn.place(x=50,y=290)
    phn1=Entry(sup,font='verdana 15')
    phn1.place(height=30,width=200,x=200,y=290)
    reg=Button(sup,text='Sign up',font='Geogrio 18',bg='peach puff',command=sign1)
    reg.place(x=230,y=340)
    sup.mainloop()
def rootm1():
    rootm=Toplevel()
    rootm.title('Desidime')
    rootm.configure(bg='turquoise')
    rootm.geometry('900x600+100+10')
    des=PhotoImage(file='./des.png')
    welcome=Label(rootm,text='Welcome',font='century 50',bg='turquoise',fg='MediumPurple3')
    welcome.place(x=570,y=0)
    des1=Label(rootm,image=des)
    des1.place(x=400,y=80)
    sign=Button(rootm,text='Sign Up',font='Calibiri 24',relief=SOLID,bg='dodger blue',fg='white',command=signup)
    sign.place(x=685,y=380)
    al=Label(rootm,text='Already Have a account ?',font='Calibiri 18',bg='turquoise')
    al.place(x=410,y=470)
    login1=Button(rootm,text='Login',font='Calibiri 24',relief=SOLID,bg='dodger blue',fg='white',command=login)
    login1.place(x=700,y=450)
    rootm.mainloop()
rootd=Tk()
rootd.geometry('+500+300')
def click():
    a=messagebox.askquestion('Welcome To Desidime',"Welcome to the India's biggest online store for Fashion, Electronics, Food delivery"+2*'\n'+'By using our app, you acknowledge that you have read and understand our Cookie Policy, Privacy Policy, and our Terms of Service'+'\n'+'Continue by accepting ?')
    if a=='yes':
        rootm1()
b=Button(rootd,text='open app',font='comic 12',command=click)
b.pack()
rootd.mainloop()
