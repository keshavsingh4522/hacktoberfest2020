# -*- coding: utf-8 -*-
"""
Created on Mon Feb  8 12:38:41 2021

@author: belimeio
"""

import json
from difflib import get_close_matches

dictionary = json.load(open("data.json"))

def translate(word):
    word = word.lower()
    keys = dictionary.keys()
    closeMatches = get_close_matches(word, keys)
    if (word in dictionary):
        return dictionary[word]
    elif (word.title() in dictionary):
        return dictionary[word.title()]
    elif (word.upper() in dictionary):
        return dictionary[word.upper()]
    elif(len(get_close_matches(word, dictionary.keys())) > 0):
        print(f'did you mean {get_close_matches(word, dictionary.keys())[0]} instead?')
        decide = input("Press y for yes or n for no.")
        if (decide == 'y'):
            return dictionary[get_close_matches(word, dictionary.keys())[0]]
        elif (decide == 'n'):
            return f"{word} doesn't found"
        else:
            print("Type only y or n")
            return f"{word} doesn't found"
    else:
        return f"{word} doesn't found"

word = input('type a word you want to search: ')
output = translate(word)
if (type(output) == list):
    for item in output:
        print(item)
else:
    print(output)