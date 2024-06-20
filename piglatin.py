from tkinter import *
from tkinter import ttk
# variables
ay = ‘ay’
way = ‘way’
consonant = (‘B’,’C’,’D’,’F’,’G’,’H’,’J’,’K’,’L’,’M’,’N’,’P’,’Q’,’R’,’S’,’T’,’Y’,’V’,’X’,’Z’)
vowel = (‘A’,’E’,’I’,’O’,’U’)
# creates Tkinter window
root = Tk()
# creates window title
root.title(‘GeekTechStuff Pig Latin’)
# stops the window being resized
root.resizable(0,0)
root.frame_box = ttk.Frame()
ttk.Label(root.frame_box,text = ‘Pig Latin Translator’, style = ‘Header.TLabel’).grid(row = 0, columnspan = 4)
ttk.Label(root.frame_box,text = ‘Text:’, style = ‘Header.TLabel’).grid(row = 3, column = 0)
ttk.Label(root.frame_box,text=’Translated Text:’,style=’Header.TLabel’).grid(row=4, column=0)
text_entry = ttk.Entry(root.frame_box, width=50)
text_entry.grid(row=3,column=1)
translated_text = ttk.Entry(root.frame_box, width=50)
translated_text.grid(row=4,column=1)
#functions
def translate_text():
pig_latin_string =”
user_sentence = text_entry.get()
user_sentence = str(user_sentence)
words = user_sentence.split()
for user_word in words:
first_letter = user_word[0]
first_letter = str(first_letter)
first_letter=first_letter.upper()
if first_letter in consonant:
length_of_word = len(user_word)
remove_first_letter = user_word[1:length_of_word]
pig_latin=remove_first_letter+first_letter+ay
pig_latin_string=pig_latin_string+’ ‘+pig_latin
elif first_letter in vowel:
pig_latin=user_word+way
pig_latin_string=pig_latin_string+’ ‘+pig_latin
else:
print(‘?’)
translated_text.insert(0, pig_latin_string)
translate_button = ttk.Button(root.frame_box,text=’Translate’,command = lambda: translate_text()).grid(row=5,column=0)
root.frame_box.pack()
root.mainloop()
