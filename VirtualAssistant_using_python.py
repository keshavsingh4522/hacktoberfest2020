import pyttsx3 as pt
import datetime
import speech_recognition as sr
import wikipedia
import webbrowser as wb
import os
import random

engine = pt.init()
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[1].id)
engine.setProperty('rate', 130)

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour>=0 and hour<12:
        speak("Good morning Bishal!")
    elif hour>= 12 and hour < 18:
        speak("Good afternoon Bishal!")
    else:
        speak("Good Evening Sir!")

    speak("I am your Assistant Sir. Please tell me how I may help you!")

def mukHun():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening....")
        r.pause_threshold = 1
        audio = r.listen(source)
    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language="en-in")
        print("You said: {}".format(query))
        speak("You said: {}".format(query))
    except:
        x = 'Sorry, I could not recognize your voice Darling! Can u say it again?'
        print(x)
        speak(x)
        return "None"
    return query

if __name__ == "__main__":
    wishMe()
    query = mukHun().lower()
        
        #logic for excuting task based on ou query
    if 'wikipedia' in query:
        speak("Searching Wikipedia....!")
        query = query.replace("wikipedia", "")
        results = wikipedia.summary(query, sentences = 2)
        speak("According to wikipedia!")
        print(results)
        speak(results)   
    elif 'open youtube' in query:
        wb.open("youtube.com")
    elif 'open google' in query:
        wb.open("google.com")
    elif 'open linkedin' in query:
        wb.open("linkedin.com")
    elif 'current temperature' in query:
        wb.open("https://weather.com/en-IN/weather/today/l/27.48,94.57?par=google&temp=c")
    elif 'open facebook' in query:
        wb.open("facebook.com")
    elif 'open' in query:
        wb.open(query + '.com')
        
    elif 'play music' in query:
        music_dir = 'D:\\backups\\Songs'  # Put the directory of your music folder
        songs = os.listdir(music_dir)
        r = random.randint(0, len(songs)-1)
        print("Currently playing: " + songs[r])
        os.startfile(os.path.join(music_dir, songs[r]))
    elif 'the time' in query:
        time = datetime.datetime.now().strftime("%H:%M:%S")
        speak("Sir, the time is {}".format(time))
    elif 'open visual studio code' in query:
        # your path may be different from mine so edit it 
        path = "C:\\Users\\LENOVO\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"
        os.startfile(path)
    elif 'my love' in query:
        # add the image folder of your crush . hehe :)
        image_dir = "D:\\her"
        images = os.listdir(image_dir)
        r2 = random.randint(0, len(images)-1)
        print("_____ is your love Sir! She is very cute and gorgeous.")
        speak("_____ is your love Sir! She is very cute and gorgeous")
        os.startfile(os.path.join(image_dir, images[r2]))
