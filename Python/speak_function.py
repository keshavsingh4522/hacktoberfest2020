import pyttsx3

'''
this will create a variable sound that'll store the sapi5
in it.and them we'll dump the voices in the sound and set it's voice to 
be male or female.
'''
sound = pyttsx3.init('sapi5')
voice = sound.getProperty('voices')
sound.setProperty('voice',voice[0].id) #voice[0] is male and voice[1] is female

def speak(audio):
    sound.say(audio)
    sound.runAndWait()
    

if __name__ == "__main__":
    acous = input("WRITE SOMETHING......\n")
    speak(acous)
    