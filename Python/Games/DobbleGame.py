#Lets play Dobble game

import string
import random
symbols =[]
symbols=list(string.ascii_letters)
card1= [0]*5
card2= [0]*5
pos1=random.randint(0,4)
pos2=random.randint(0,4)
print(pos1)
print(pos2)
samesymbol=random.choice(symbols)
symbols.remove(samesymbol)
if(pos1==pos2):
    card2[pos1]=samesymbol
    card1[pos1]=samesymbol
else:
    card1[pos1]=samesymbol
    card2[pos2]=samesymbol
    card1[pos2]=random.choice(symbols)
    symbols.remove(card1[pos2])
    card2[pos1]=random.choice(symbols)
    symbols.remove(card2[pos1])
i=0
while(i<5):
    if(i!=pos1 and i!=pos2):
        alphabet1=random.choice(symbols)
        symbols.remove(alphabet1)
        alphabet2=random.choice(symbols)
        symbols.remove(alphabet2)
        card1[i]=alphabet1
        card2[i]=alphabet2
    i=i+1
print(card1)
print(card2)
ch=input("Spot the similar symbol: ")
if(ch==samesymbol):
    print("You Are Right!!")
else:
    print("Sorry, Wrong!")
