#! /usr/bin/python3

'''
Program to keep the screen on while away
'''

import time
import pyautogui

#if FAILSAFE=True then move the cursor to top left side of the screen to exit the program
pyautogui.FAILSAFE = True

#pause for 10 sec
time.sleep(10)

#move the mouse pointer to given location
for i in range(10):
    pyautogui.moveTo(100, i*5)

pyautogui.press('shift')
