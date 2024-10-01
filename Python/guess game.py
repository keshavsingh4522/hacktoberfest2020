'''
Made by : Aun Muhammad 
github ID : AunMuhammad1

'''



'''
Game rule*
    1). Enter you name. 
    2). You have 5 number of tries for guessing.


'''
my_name = input("Enter your name: \t")
if my_name.isnumeric():
    my_name = str(my_name)
else:
    print("Please enter you name in string..")
tries = 0
total_tries = 5
import random
number = random.randint(1,50)
print(f"Well {my_name}, \nyou only think number between 1 and 50. ")
for tries in range(5):
    print(f"let go! \nPlay game {my_name}.")
    guess = input("Take a guess.\t")
        

    if guess.isnumeric():
        guess = int(guess)
    else:
        print("Invalid input!. Please enter integer value only.")
            
    if guess < number:
        print(f"{my_name} your guess is less then the guess number. \nPlease enter some big value.")
        total_tries = total_tries - 1
        print(f"{my_name} your tries left are {total_tries} ")
    elif guess > number:
        print(f"{my_name} your guess is greater then the guess number. \nPlease enter some small value.")
        total_tries = total_tries - 1
        print(f"{my_name} your tries left are {total_tries} ")
    elif guess == number:
        break
        
        
if guess != number:
    print(f"Nobe, {my_name}. \n These numbers {guess} that your are think was not a guess number. \n The guess number is {number}.")
elif guess == number:
    print(f"GOOD JOB!, {my_name}. \nCongratuation. You guess my number in {number}. ")