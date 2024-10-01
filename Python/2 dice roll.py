import random
#random generate random number.
class Dice:
    def roll(self):
        first=random.randint(1,6)
        sec=random.randint(1,6)
        return first,sec

dice1=Dice()
print(dice1.roll())
