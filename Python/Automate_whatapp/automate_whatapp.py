import time
import pyautogui

def send():
  time.sleep(10)
  text=open('message.txt')
  for each_line in text:
    pyautogui.typewrite(each_line)
    pyautogui.press('enter')

    
#Completely automating this with chrome use the code above or below

import webbrowser
import pyautogui
import webbrowser
import time

print("you have to wait for 25 seconds for it to start ")

fword = input("ENTER THE TEXT TO BE SPAMMED")
N=input("enter the number of times you want it to be spammed")


webbrowser.open_new("https://web.whatsapp.com/")
time.sleep(30
)

# ENTER THE AMOUNT OF TIMES YOU WANT TO SPAM AFTER range ie range(x)
for i in range(N-1):
    pyautogui.typewrite(fword)
    pyautogui.press("enter")
send()
