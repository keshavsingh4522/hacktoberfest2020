from tkinter import *
from tkinter.ttk import Combobox
from math import *
import os
from datetime import datetime, timedelta
#-----------------------------

def EquiRectDist(lat1,long1,lat2,long2):
    R=6371*(10**3)  #radius of earth
    x=(long2-long1)*cos((lat1+lat2)/2)
    y=lat2-lat1
    d=sqrt((pow(x,2))+pow(y,2))*R
    return d
    
def EquiRectDistDeg(lat1,long1,lat2,long2):
    return (EquiRectDist(radians(lat1),radians(long1),radians(lat2),radians(long2)))



def calculate():
    fn=(e1.get())
    fo=open(fn,"r")
    lat=[]
    long=[]
    time=[]
    i=0
    if(fn=="gps.csv"):
        for l in fo.readlines():
            L=l.split(";")
            print(L)
            if(i>0):
                lat.append(float(L[0]))
                long.append(float(L[1]))
                time.append(float(L[-1]))
            i=i+1
    else:
        for l in fo.readlines():
            L=l.split(",")
            print(L)
            if(i>0):
                lat.append(float(L[0]))
                long.append(float(L[1]))
                time.append(float(L[-1]))
            i=i+1
    LL=[lat,long]
    tt=time[-1]-time[0]
    ttt=tt
    sec = timedelta(seconds=ttt*(10**(-3)))
    d = datetime(1,1,1)+sec
    print("DAYS:HOURS:MIN:SEC")
    print("%d:%d:%d:%d" % (d.day-1,d.hour,d.minute,d.second))
    ttt = str(int(d.day-1))+"days "+str(int(d.hour))+"hrs "+str(int(d.minute))+"min. "+str(int(d.second))+"sec. "
    

   
    
    d=0
    for a in range(0,len(LL[0])-1):
        d=d+(EquiRectDistDeg((LL[0][a]),(LL[1][a]),(LL[0][a+1]),(LL[1][a+1])))
        
    #sec=timedelta(seconds=int(tt*10**(-3)))
    #y=datetime(1,1,1)+sec
    #ttt=str(y.day-1," ",y.hour," ",y.minute," ",y.second)
    X.set(str(round(d,3))+"  m")
    Y.set(str(ttt))
    Z.set(str(round(d/(tt*10**(-3)),3))+"  m/s")

def hello():
    Lcsv=[]
    f=os.path.abspath('.')
    L=os.listdir(f)
    for i in L:
        if ('.csv' in i):
            Lcsv.append(i)
    return Lcsv

#----------------------------
#Main Page
#----------------------------
window=Tk()
window.title("distance using latitude and longitutude")

#30.516077
#76.659649
#48.814668
#2.213897
l1=Label(window,text="FileName : ")
l1.grid(row=0,column=0)

l2=Label(window,text="distance : ")
l2.grid(row=1,column=0)

l3=Label(window,text="time : ")
l3.grid(row=2,column=0)

l4=Label(window,text="speed : ")
l4.grid(row=3,column=0)

e1=Combobox(window,values=hello())
e1.grid(row=0,column=1)

X=StringVar()
d1=Label(window,textvariable=X,bg="beige")
d1.grid(row=1,column=1)

Y=StringVar()
d1=Label(window,textvariable=Y,bg="beige")
d1.grid(row=2,column=1)

Z=StringVar()
d1=Label(window,textvariable=Z,bg="beige")
d1.grid(row=3,column=1)

b1=Button(window,text="Quit",command=quit) #in other terminal we use window.destroy()
b1.grid(row=4,column=0)

b2=Button(window,text="Calculate",command=calculate)
b2.grid(row=4,column=2)
