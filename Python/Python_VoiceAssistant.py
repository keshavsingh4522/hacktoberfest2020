import pyttsx3
import datetime
import pywhatkit
import wikipedia
from GoogleNews import GoogleNews
import webbrowser
import speech_recognition as sr
engine=pyttsx3.init('sapi5')
voices=engine.getProperty('voices')

engine.setProperty('voice',voices[0].id)


def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def wishMe():
    hour=float(datetime.datetime.now().hour)
    print(hour)
    if(hour>=0 and hour<10):
        speak("good morning")
    elif hour<=10 and hour<18:
        speak("good after noon")
    else:
        speak("good evening")
    
    speak("i am python how can i help you")
    
wishMe()

def takeCommand():
    r=sr.Recognizer()
    with sr.Microphone() as source:
        print("listening......")
        r.pause_threshold=1
        audio=r.listen(source)

    try:
        print("recognizing...")
        query= r.recognize_google(audio,language='en-in')
        print(query)

    except  Exception as e:
        print(e)

        print("say again")
        return "None"
    return query


def runPy():
    command=takeCommand()
    print(command)
    if 'play' in command:
        song=command.replace('play','')
        speak("playing")
        print('playing')
        pywhatkit.playonyt(song)
    elif 'time' in command:
        time=datetime.datetime.now().strftime('%I:%M %p')
        speak("current time is"+time)
        print(time)
    elif 'Wikipedia' in command:
        key=command.replace("wikipedia","")
        info=wikipedia.summary(key)
        print(info)
        speak(info)
    elif 'news' in command:
        news=GoogleNews(lang='en')
        speak(news)
    elif 'open YouTube' in command:
        webbrowser.open("youtube.com")
        speak("openning")
    elif 'open Google' in command:
        webbrowser.open("google.com")
        speak("openning")




runPy()



        
takeCommand()


