import time
import pyautogui

def send():
  time.sleep(10)
  text=open('mymessage.txt')
  for each_line in text:
    pyautogui.typewrite(each_line)
    pyautogui.press('enter')

send()
