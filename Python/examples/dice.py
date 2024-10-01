# -*- coding: utf-8 -*-
"""
Created on Mon Feb  8 11:22:35 2021

@author: belimeio
"""

import random

def roll():
    return random.randint(1, 6)

def printDice(a):
    print('---------\n')
    if (a == 1):
        print('|       |\n')
        print('|   0   |\n')
        print('|       |\n')
    elif(a == 2):
        print('|       |\n')
        print('|  0  0 |\n')
        print('|       |\n')
    elif(a == 3):
        print('|   0   |\n')
        print('|   0   |\n')
        print('|   0   |\n')
    elif(a == 4):
        print('|  0  0 |\n')
        print('|       |\n')
        print('|  0  0 |\n')
    elif(a == 5):
        print('|  0  0 |\n')
        print('|   0   |\n')
        print('|  0  0 |\n')
    elif(a == 6):
        print('|  0  0 |\n')
        print('|  0  0 |\n')
        print('|  0  0 |\n')
    print('---------\n')