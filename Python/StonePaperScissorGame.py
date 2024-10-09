#Importing random
import random

#creating a list of elements of game and define variable.
elements = ["Stone","Scissor","Paper"]
global human #global for using the variabe in function
global com 
human = 0
com = 0

#for displaying choices.
def display_choices():
    print("Now you're going to play Stone Paper Scissor game.")
    print("You need 10 points to win the match.")
    print("Here are your Choices :- ")
    print("Stone   : 1")
    print("Scissor : 2")
    print("Paper   : 3")
    
#main gameplay.     
def play_game(human,com):
    
    #humanc =  int(input("Enter the choice here 1-3 : "))
    num = int(input("Enter the choice here 1-3 : "))
    humanc = validate(num)
        
    comc = random.randint(1,3)
    display_result(humanc, comc)
    
    winner(humanc, comc)
   
    points()

#for decide who is winner.
def winner(c1,c2):
    global com
    global human 
    if c1 == c2:
        print("Draw")
        return None
    elif c1 < c2 :
        if c1 == 2 and c2==3:
            human += 1
            print("Congratulations!...You Win.")
            return None
        elif c2 != 3:
            human += 1
            print("Congratulations!...You Win.")
            #print(f"P1 : {human}")
            return None
        else:
            com+=1
            print("Oops!...Best of luck next time.")
            # print(f"P2 : {com}")
            return None
    elif c2 < c1 :
        if c2 == 2 and c1==3:
            com += 1
            print("Oops!...Best of luck next time.")
            return None
        elif c1 != 3:
            print("Oops!...Best of luck next time.")
            com += 1
            #print(f"P1 : {human}")
            return None
        else:
            human+=1
            print("Congratulations!...You Win.")
            # print(f"P2 : {com}")
            return None

#for desplaying result.    
def display_result(c1,c2):
    
    print(f"You choose : {elements[c1-1]}") 
    print(f"Computer choose : {elements[c2-1]}") 

#validating the entered choice.    
def validate(num):
    if num < 0 or num > 3:
        num = int(input(("Enter the valid choice : ")))
        num = validate(num)

    return num

#Calculating points.
def points():
    print(f"Your Points     :{human}")
    print(f"Computer Points :{com}")

#final result 
def final(p1,p2):
    if (p1 == 10 ):
        print(f"You win by {p1-p2}")
    elif (p2 == 10):
        print(f"You lose by {p2-p1}")
    return None
# def get_choice():    
# human_choice : int(input("Enter the choice here 1-3 : "))
#     return human_choice
 
# def get_random():
#     com_choice = random.randint(1,3)
#     return com_choice

display_choices()
i =30
#loop for playing the match 
while(i < 40):
    if human == 10 or com == 10:
        i = 40
        print()
        final(human,com)        
    else:   
        print()
        play_game(human,com)
