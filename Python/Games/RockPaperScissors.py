import random

lst = ['r', 'p', 's']

chance = 10
no_of_chance = 0
computer_point = 0
human_point = 0

# print(" \t \t \t \t Rock,Paper,Scissors Game\n \n")
print("r for rock \np for paper \ns for scissors \n")
username = input("Enter your name")


while no_of_chance < chance:
    _input = input('Rock,Paper,Scissors:')
    _random = random.choice(lst)

    if _input == _random:
        print("Tie Both 0 point to each \n ")

    # if user enter s
    elif _input == "r" and _random == "p":
        computer_point = computer_point + 1
        print(f"{username} took {_input} and computer took {_random} \n")
        print("computer wins 1 point \n")
        print(f"computer's point are {computer_point} and {username}'s points are {human_point} \n ")

    elif _input == "r" and _random == "s":
        human_point = human_point + 1
        print(f"{username} took {_input} and computer took {_random} \n")
        print(f"{username} wins 1 point \n")
        print(f"computer's point are {computer_point} and {username}'s points are {human_point} \n ")

    # if user enter w
    elif _input == "p" and _random == "s":
        computer_point = computer_point + 1
        print(f"{username} took {_input} and computer took {_random} \n")
        print("computer wins 1 point \n")
        print(f"computer's point are {computer_point} and {username}'s points are {human_point} \n ")

    elif _input == "p" and _random == "r":
        human_point = human_point + 1
        print(f"{username} took {_input} and computer took {_random} \n")
        print(f"{username} wins 1 point \n")
        print(f"computer's point are {computer_point} and {username}'s points are {human_point} \n ")
    # if user enter g

    elif _input == "s" and _random == "p":
        human_point = human_point + 1
        print(f"{username} took {_input} and computer took {_random} \n")
        print(f"{username} win 1 point \n")
        print(f"computer's point are {computer_point} and {username}'s points are {human_point} \n ")


    elif _input == "s" and _random == "r":
        computer_point = computer_point + 1
        print(f"{username} took {_input} and computer took {_random} \n")
        print("computer wins 1 point \n")
        print(f"computer's point are {computer_point} and {username}'s points are {human_point} \n ")

    else:
        print("please enter a valid input \n")

    if _input == 'r' or _input == 's' or _input == 'p':
        no_of_chance = no_of_chance + 1
    print(f"{chance - no_of_chance} chances are left out of {chance} chances\n")

print("Game over")

if computer_point == human_point:
    print("Tie")

elif computer_point > human_point:
    print(f"Computer wins and {username} looses")

else:
    print(f"{username} wins and computer looses")

print(f"{username}: {human_point} :: Computer {computer_point}")



