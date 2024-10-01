# -*- coding: utf-8 -*-
"""
Created on Mon Feb  8 11:43:15 2021

@author: belimeio
"""

import dice
from dice import *

x = 'y'
while(x == 'y'):
    diceNum = dice.roll()
    dice.printDice(diceNum)
    x = input('type y to roll again: ')