import hangman_art
import hangman_words
import random
from os import system, name
def clear():
  
    # for windows
    if name == 'nt':
        _ = system('cls')
  
    # for mac and linux(here, os.name is 'posix')
    else:
        _ = system('clear')

print(hangman_art.logo)
end_of_game = False
chosen_word = random.choice(hangman_words.word_list)
word_length = len(chosen_word)

lives = 7

#Create blanks
display = []
for _ in range(word_length):
  display += "_"

while not end_of_game:
  guess = input("\nGuess a letter: ").lower()
  
  clear()

  if guess in display:
    print("\nYou have already entered the letter.")
    continue

  if guess not in chosen_word:
    lives -= 1
    print(f"\nWrong guess! Lives remaining: {lives}\n{hangman_art.stages[lives]}")
    if lives == 0:
      print("No lives remaining. You lose!")
      print(f"\nThe word was {chosen_word}.")
      end_of_game = True
      continue
    print(f"{' '.join(display)}")
    continue
  
  #Check guessed letter
  for position in range(word_length):
    letter = chosen_word[position]
    if letter == guess:
      display[position] = letter
  print("\nCorrect!") 

    #Join all the elements in the list and turn it into a String.
  print(f"{' '.join(display)}")

    #Check if user has got all letters.
  if "_" not in display:
    end_of_game = True
    print("\nYou win!")
