import random

random_number = random.randint(0, 100)
print("Hello, What is your name?")
my_name = input()
print("Hi, {}! We will be playing a guessing game.".format(my_name))
print("Well, {} I am thinking of a number between 1 to 99".format(my_name))
print("You have to guess it in 7 chances.")
chances = 0
for gusses in range(1, 7):
    print("Take a guess")
    guess = int(input())
    chances += 1
    if guess > random_number:
        print("Your number is too high!")
    elif guess < random_number:
        print("Your number is too low!")
    else:
        break

if random_number == guess:
    print(
        "Good job {}, You guessed the number in {} chances, I was thinking of {}".format(
            my_name, chances, random_number
        )
    )
else:
    print("Oops, You Lost! I was thinking of {}".format(random_number))
