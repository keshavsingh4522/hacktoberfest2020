import pyttsx3                      # pip install pyttsx3
import datetime
import speech_recognition as sr     # pip install speech_recognition
import wikipedia                    # pip install wikipedia
import smtplib
import webbrowser as wb
import psutil                       # pip install psutil
import pyjokes                      # pip install pyjokes
import os
import pyautogui                    # pip install pyautogui
import wolframalpha                 # pip install wolframalpha
import tkinter as tk
from tkinter import filedialog
import json
from urllib.request import urlopen
import time


engine = pyttsx3.init()
wolframalpha_app_id = '725EY8-2JJ8XA7E4H'

def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def time_():
    Time = datetime.datetime.now().strftime("%I:%M:%S")     # H is for 24 hrs clock and I for 12 hrs clock
    speak("The current time is")
    speak(Time)


def joke():
    speak(pyjokes.get_joke())


def screenshot():
    img = pyautogui.screenshot()
    img.save("screenshot.png")


def date_():
    year = datetime.datetime.now().year
    month = datetime.datetime.now().month
    day = datetime.datetime.now().day
    speak('The current date is')
    speak(day)
    speak(month)
    speak(year)


def wish_me():
    speak("Welcome back Ayush!")
    time_()
    date_()

    # greeting
    hour = datetime.datetime.now().hour

    if hour>=6 and hour<12:
        speak("Good Morning Sir!")
    elif hour>=12 and hour<18:
        speak("Good Afternoon Sir!")
    elif hour>=18 and hour<24:
        speak("Good Evening Sir!")
    else:
        speak("Good Night Sir!")
    speak("Jarvis at your Service how can i help you")


def send_email(to, content):
    server = smtplib.SMTP('smtp.gmail.com', 587)
    server.ehlo()
    server.starttls()                   # FOR THIS FUNCTION YOU MUST ENABLE LOW SECURITY IN YOUR GMAIL ACCOUNT
    server.login('jarvis1.0aj@gmail.com', 'qwerty123@')
    server.sendmail('jarvis1.0aj@gmail.com', to, content)
    server.close()


def cpu():
    usage = str(psutil.cpu_percent())
    speak('CPU is at' +usage)
    battery = psutil.sensors_battery()
    speak("battery is ")
    speak(battery.percent)
    temp = psutil.sensors_temperatures()
    speak('current temperature is'+temp)


def Take_command ():
    r=sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening.........")
        r.pause_threshold = 1
        audio = r.listen(source)
    try:
        print("Recognizing.......")
        query = r.recognize_google(audio,language='en-US')
        print(query)

    except Exception as e:
        print(e)
        print("Sorry can you say it again..........")
        return "None"
    return query


if __name__ == "__main__":

    wish_me()
    while True:
        query = Take_command().lower()
# All commands will be stored in lower case in query
        if 'time' in query:                 # tell us time when asked
            time_()

        elif 'date' in query:               # Tell us date when asked
            date_()

        elif 'wikipedia' in query:
            speak('searching')
            query = query.replace('wikipedia', '')
            result = wikipedia.summary(query,sentences=4)
            speak('According to Wikipedia')
            print(result)
            speak(result)

        elif 'send mail' in query:
            try:
                speak('What should i say!')
                content = Take_command()
# PROVIDE RECIEVER EMAIL ADDRESS
                speak('Who is the Reciever ?')
                reciever = input("ENTER RECIEVER'S EMAIL ADDRESS:")
                to = reciever
                send_email(to,content)
                speak(content)
                speak('Email has been sent.')
            except Exception as e:
                print(e)
                speak("unable to send Email.")

        elif 'search in chrome' in query:
            speak('what to search?')
            chromepath = r'C:\Program Files (x86)\Google\Chrome\Application\chrome.exe %s'
# chromepath stores the chromes location
            search = Take_command().lower()
            wb.get(chromepath).open_new_tab(search+'.com')
# It only search for websites ending with .com
        elif 'search youtube' in query:
            speak('what should i search?')
            search_term = Take_command().lower()
            speak("HERE WE go to YOUTUBE!")
            wb.open('https://www.youtube.com/result?search_query='+search_term)

        elif 'search google' in query:
            speak('what should i search?')
            search_term = Take_command().lower()
            speak("HERE WE go to GOOGLE!")
            wb.open('https://www.google.com/search?q=' + search_term)

        elif 'cpu' in query:
            cpu()

        elif 'joke' in query:
            joke()

        elif 'go offline' in query:
            speak('Going off line sir!')
            quit()

        elif 'word' in query:
            speak('Opening MS Word...')
            ms_word = r'C:\Program Files\Microsoft Office\root\Office16\WINWORD.EXE'
            os.startfile(ms_word)

        elif 'write a note' in query:
            speak('what should i write, sir?')
            notes = Take_command()
            file = open('note.txt', 'a')
            speak('sir should i include Date and time?')
            ans = Take_command().lower()
            if 'yes' in ans or 'sure' in ans:
                strTime =datetime.datetime.now().strftime("%H:%M:%S")
                file.write(strTime)
                file.write(":-")
                file.write(notes)
                speak('Done taking notes.')
            else:
                file.write(notes)
                speak('Done taking notes, sir!')
                file.close()

        elif 'show note' in query:
            file = open('note.txt', 'r')
            print(file.read())
            speak(file.read())

        elif 'screenshot' in query:
            screenshot()

        elif 'play_music' in query:
            
            song_dr = filedialog.askopenfilename()
            music = os.listdir(song_dr)
            speak('what should i play?')
            ans = Take_command().upper()
            no = int(ans.replace('number', ''))
            os.startfile(os.path.join(song_dr, music[no]))

        elif 'remember that' in query:
            speak('What should i remember,sir?')
            memory =Take_command()
            speak('you asked me to remember that'+memory)
            remember = open('memory.txt', 'a')
            remember.write(memory)
            remember.close()

        elif 'do you remember anything' in query:
            remember =open('memory.txt', 'r')
            speak('You asked me to remember that'+remember.read())
            remember.close()

        elif 'news' in query:
            try:
                jsonObj = urlopen('http://newsapi.org/v2/top-headlines?sources=techcrunch&apiKey=8310479d0e7f473fad636f532b41b8b0')
                data = json.load(jsonObj)
                i = 1
                speak("Here are some top headline from you")
                print("==========TOP HEADLINES==========")
                for item in data['articles']:
                    print(str(i)+ ':'+item['title']+'\n')
                    print(item['description']+'\n\n')
                    speak(item['title'])
                    i=i+1
            except Exception as e:
                print(str(e))

        elif 'where is' in query:
            location = query.replace("where is","")
            speak("you asked me to locate"+ location)
            wb.open_new_tab("https://www.google.com/maps/place/"+location)

        elif 'calculate' in query:
            client = wolframalpha.Client(wolframalpha_app_id)
            indx = query.lower().split().index('calculate')
            query = query.split()[indx+ 1:]
            res = client.query(''.join(query))
            answer = next(res.results).text
            print('the Answer is :'+answer)
            speak('the Answer is :'+answer)

        elif 'what is' in query or 'who is ':
            client = wolframalpha.Client(wolframalpha_app_id)
            res = client.query(query)
            try:
                print(next(res.results).text)
                speak(next(res.results).text)
            except StopIteration:
                print('no result found!')
                speak('No result found!')

        elif 'stop listening' in query:
            speak('For How many seconds ,sir')
            ans = int(Take_command())
            time.sleep(ans)
            print(ans)
            
        elif 'close' in query:
            exit()
# GIVING COMPUTERS CONTROLS

        elif 'log out' in query:
            os.system("shutdown -1")
        elif 'restart' in query:
            os.system("shutdown /r /t 1")
        elif 'shutdown' in query:
            os.system("shutdown /s /t 1")

        else:
            speak("SORRY I DON'T KNOW")
