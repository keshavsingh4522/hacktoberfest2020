# contributed by Manan Bansal 

import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia
import webbrowser
import os
import smtplib


engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
#print(voices.id)
engine.setProperty('voice',voices[1].id)



def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def wishme():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0  and hour < 12 :
        speak("Good Morning")
    elif hour >= 12 and hour < 18 :
        speak(" Good Afternoon ")
    else :
        speak("Good Evening")

    speak("I am your assistant . How may i help you")


def takecommand():
    r=sr.Recognizer()

    with sr.Microphone() as source :
        print("Listening..........")
        r.pause_thresold = 1
        audio = r.listen(source)

    try:
        print("Recognising.....")
        query= r.recognize_google(audio ,language ='en-in')
        print(f"user said {query}\n")

    except exception as e:
        print("Say that again please.....")
        return "none"
    return query


def sendEmail( to, content) :
    server = smtplib.SMTP('smtp.gmail.com',587)
    server.ehlo()
    server.starttls()
    server.login('youremail@gmail.com', 'your password')
    server.sendmail('youremail@gmail.com', to , content)
    server.close()


if __name__=="__main__" :
    wishme()
    if 1:
        query = takecommand().lower()
        if wikipedia in query :
            speak("Searching Wikipedia.....")
            results = wikipedia.summary(query.replace(wikipedia) , sentence=2)
            speak("According to wikipedia")
            print(results)
            speak(results)

        elif 'open youtube' in query :
            webbrowser.open("youtube.com")

        elif 'open google' in query :
            webbrowser.open("google.com")

        elif 'open stackoverflow' in query :
            webbrowser.open("stackoverflow.com")

        elif 'open reddit' in query :
            webbrowser.open("reddit.com")

        elif 'open insta' in query :
            webbrowser.open("instagram.com")

        elif 'play music' in query :
            music_dir = "file path"
            songs=os.listdir(music_dir)
            os.startfile(os.path.join(music_dir,song(0)))

        elif 'time' in query :
            strtime=datetime.datetime.now().strftime("%H:%M:%S")
            speak(f"sir , time is {strtime}")

        elif 'open pycharm' in query :
            codepath= "C:\\Program Files\\JetBrains\\PyCharm Community Edition 2020.2.2\\bin\pycharm64.exe"
            os.startfile(codepath)

        elif 'email to parth' in query:
            try:
                speak("What Shout i say?")
                content = takecommand()
                to = "manan.bansal.1806@gmail.com"
                sendEmail(to,content)
                speak("Email has been sent")
            except Exceptionas e:
                print(e)
                speak("Sorry Sir couldnt send your email..")