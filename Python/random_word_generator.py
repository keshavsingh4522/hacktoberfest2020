word_list = ["jeeban","sethi","kumar"]
import random
chosen_word = random.choice(word_list)
guess = input("GUess a letter:").lower()
for letter in chosen_word:
    if letter == guess:
        print("Right")
    else:
        print("Wrong")