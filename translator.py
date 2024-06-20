from translate import Translator

Translator = Translator(to_lang="en")
try:
    with open('translator/text.txt', mode='r') as my_file:
        text = my_file.read()
        translate = Translator.translate(text)
        print(translate)
except FileNotFoundError as e:
    print('check your file path silly!')        