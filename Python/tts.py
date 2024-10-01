from tkinter import *
from gtts import gTTS
import playsound
from tkinter import*
import os 
from playsound import playsound
#note : need to pip install playsound==1.2.2 

root=Tk()
#main window
root.geometry("400x400")
root.configure(bg='black')
root.title("Panav's TTS")
#Tk() to initialized tkinter which will be used for GUI
#geometry() used to set the width and height of the window
#configure() used to access window attributes
#bg will used to set the color of the background
#title() set the title of the window
Label(root, text="Text To Speech", font="helvetica 20 bold",bg='white smoke', width='25').pack(side='bottom')
#Label() widget is used to display one or more than one line of text that users can’t able to modify.

#text which we display on the label
#font in which the text is written
#pack organized widget in block
#Msg is a string type variable
#Entry() used to create an input text field
#textvariable used to retrieve the current text to entry widget
#place() organizes widgets by placing them in a specific position in the parent 
Msg = StringVar()
Label(root,text ="Enter Text", font = 'arial 15 bold', bg = "lightpink").place(x=20,y=60)
entry_field = Entry(root, textvariable = Msg ,width ='60')
entry_field.place(x=20,y=100)
def Text_to_speech():
    Message = entry_field.get()
    speech = gTTS(text = Message)
    os.remove('DataFlair.mp3')
    speech.save('DataFlair.mp3')
    playsound('DataFlair.mp3')
#Message variable will stores the value of entry_field
#text is the sentences or text to be read.
#lang takes the language to read the text. The default language is English.
#slow use to reads text more slowly. The default is False.
#As we want the default value of lang, so no need to give that to gTTS.

#speech stores the converted voice from the text
#speech.save(‘DataFlair.mp3’) will saves the converted file as DataFlair as mp3 file
#playsound() used to play the sound
def Exit():
    root.destroy()
def Reset():
    Msg.set("")

Button(root, text = "PLAY", font = 'arial 15 bold' , command = Text_to_speech ,width = '4').place(x=25,y=140)

Button(root, font = 'arial 15 bold',text = 'EXIT', width = '4' , command = Exit, bg = 'OrangeRed1').place(x=100 , y = 140)

Button(root, font = 'arial 15 bold',text = 'RESET', width = '6' , command = Reset).place(x=175 , y = 140)
root.mainloop()
