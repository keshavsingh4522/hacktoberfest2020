
import random
print("\n ********** WELCOME TO ROCK || PAPER || SCISSOR ************\n")
n=int(input("Enter how many games you want to play : \n")) 

list1=["Rock, Paper, Scissor"]
d1={1:"Rock",2:"Paper",3:"Scissor"}

p_score=0  # Player Score
c_score=0  # Computer Score

while(n>0):
    print("\nEnter your choice :\nPress 1 for Rock \nPress 2 for Paper \nPress 3 for Scissor")
    a=int(input())

    comp=random.choice(list1)

    if(a==1): # Rock
        if(comp=="Rock"):
            print("\nYour choice : ",d1[1])
            print("Computer choice : ",comp)
            print("Tie !!")
        elif(comp=="paper"):
            print("\nYour choice : ", d1[1])
            print("Computer choice : ", comp)
            print("You loose... Computer won !!")
            c_score=c_score+1
        else:
            print("\nYour choice : ", d1[1])
            print("Computer choice : ", comp)
            print("You Won !!")
            p_score=p_score+1

    elif (a == 2): 

        if (comp == "Rock"):
            print("\nYour choice : ", d1[1])
            print("Computer choice : ", comp)
            print("You Won !!")
            p_score = p_score + 1

        elif (comp == "paper"):
            print("\nYour choice : ", d1[1])
            print("Computer choice : ", comp)
            print("Tie !!")

        else:
            print("\nYour choice : ", d1[1])
            print("Computer choice : ", comp)
            print("You loose... Computer won !!")
            c_score = c_score + 1

    elif (a == 3):

        if (comp == "Rock"):
            print("\nYour choice : ", d1[1])
            print("Computer choice : ", comp)
            print("You loose... Computer won !!")
            c_score = c_score + 1

        elif (comp == "paper"):
            print("\nYour choice : ", d1[1])
            print("Computer choice : ", comp)
            print("You Won !!")
            p_score = p_score + 1

        else:
            print("\nYour choice : ", d1[1])
            print("Computer choice : ", comp)
            print("Tie !!")

    else:
        print("YOU ENETERED WRONG CREDENTIALS.. PLEASE RUN THE PROGRAM AGAIN TO PLAY !!")
        break

    n=n-1  # for reducing the chances

print("\n\n")
print("Your score : ",p_score)
print("Computer Score : ",c_score)
print("\n")
if p_score>c_score:
    print(" ************* CONGRATULATIONS !! You won maximum rounds ***************")
elif c_score>p_score:
    print(" ********** HARD LUCK !! System won maximum rounds ************")
else:
    print(" **************** DRAW !! ******************")
