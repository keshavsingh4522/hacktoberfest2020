# -*- coding: utf-8 -*-
"""
Created on Mon Feb  8 16:49:38 2021

@author: belimeio
"""
import random

def hangman():
    words = ['apple', 'banana', 'lemon', 'orange', 'mango', 'passion', 'grapes', 'watermellon', 'mellon']
    word = random.choice(words)
    validLetters = 'abcdefghijklmnopqrstuvwxyz'
    turns = 10
    guessMade = ''
    while len(word)>0:
        main = ''
        missed = 0
        
        for letter in word:
            if letter in guessMade:
                main += letter
            else:
                main += '_'
        if main == word:
            print(main)
            print('You win!')
            break
        print(f'Guess the word: {main}')
        guess = input()
        if guess in validLetters:
            guessMade += guess
        else:
            print("enter valid character")
            guess = input()
        if guess not in word:
            turns = turns - 1
            if turns == 9:
                print('9 turns left')
                print('---------------')
            if turns == 8:
                print('8 turns left')
                print('---------------')
                print('       O       ')
            if turns == 7:
                print('7 turns left')
                print('---------------')
                print('       O       ')
                print('       |       ')
            if turns == 6:
                print('6 turns left')
                print('---------------')
                print('       O       ')
                print('       |       ')
                print('      /        ')
            if turns == 5:
                print('5 turns left')
                print('---------------')
                print('       O       ')
                print('       |       ')
                print('      /\       ')
            if turns == 4:
                print('4 turns left')
                print('---------------')
                print('     \ O       ')
                print('       |       ')
                print('      /\       ')
            if turns == 3:
                print('3 turns left')
                print('---------------')
                print('     \ O /      ')
                print('       |       ')
                print('      /\       ')
            if turns == 2:
                print('2 turns left')
                print('---------------')
                print('     \ O|/     ')
                print('       |       ')
                print('      /\       ')
            if turns == 1:
                print('1 turns left')
                print('last turn')
                print('---------------')
                print('     \ O_|/      ')
                print('       |       ')
                print('      /\       ')
            if turns == 0:
                print('You loose')
                print('---------------')
                print('       O_|      ')
                print('      /|\      ')
                print('      /\       ')
                break
            
    
name = input("type your name: ")
print("Welcome {name}")
print("--------------")
print("try to guess the word in less than 10 tries")
print()
hangman()