import random
import os
import sys
import logging
from twilio.rest import Client
from PyDictionary import PyDictionary
import pronouncing
dictionary=PyDictionary()

account_sid = 'place acc sid here '
auth_token = 'place acc token here '
client = Client(account_sid, auth_token)


dataset_path = r"word_dataset.txt"
           
# shuffling words in the word_dataset
lines = open(dataset_path).readlines()
random.shuffle(lines)
open(dataset_path, 'w').writelines(lines)

#reading a random word from the dataset 
lines = open(dataset_path).read().splitlines()
my_word = str(random.choice(lines))
print(my_word)
# word data 
word_meaning = dictionary.meaning(my_word)
word_synonym = dictionary.getSynonyms(my_word)
word_pronounce = pronouncing.phones_for_word(my_word)
word_of_the_day = str(f''' word of the day : {my_word}. meaning of the day :{word_meaning}. the synonyms for it is: {word_synonym}. and the pronouncation for the
day is : {word_pronounce}''')
            
                             
try:
    message = client.messages \
                    .create(
                        body=str(word_of_the_day),
                        from_='whatsapp:+14155238886',
                        to='whatsapp:"put whatsapp number here"'
                    )

    print(message.sid)
except:
    sg.popup("unable to send message")


    



