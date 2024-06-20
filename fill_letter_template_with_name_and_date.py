import datetime

dt = datetime.datetime.now()

letter = '''Dear <|NAME|>,

You are selected!

Date : <|DATE|>'''

name = input("Please enter your name :\n")

day = dt.strftime("%d")
month = dt.strftime("%B")
year = dt.strftime("%Y")
date = day + " " + month + ", " + year

letter = letter.replace("<|NAME|>", name)
letter = letter.replace("<|DATE|>", date)

print(letter)