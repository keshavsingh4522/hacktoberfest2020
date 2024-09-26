import os,random,time
os.system('cls')
print('Stone:s\n'
      "Paper:p\n"
      "Scissor:sc\n")
compwin  = 0
hmwin = 0
chances = 10
# From here the logic begins  ->   choice==human and rand==computer
# Some template code -> print("You Won!😇")    print("You lost!😔")
while chances>0:
    choice = input("Enter your choice\n")
    list1 = ['sc','p','s']
    rand  = random.choice(list1)
    sent = f"Your Choice:{choice}\nComputer chose:{rand}"
    print(sent)
    if choice=="s" and rand=="s":
        print("It is a tie!")
        # chances-=1
        something = f"You are left with {chances} chances"
        print("")
        print(something)
    elif choice=="p" and rand=="p":
        print("It is a tie!")
        # chances-=1
        something = f"You are left with {chances} chances"
        print("")
        print(something)
    elif choice=="sc" and rand=="sc":
        print("It is a tie!")
        # chances-=1
        something = f"You are left with {chances} chances"
        print("")
        print(something)
    elif choice=="s" and rand=="p": #Straight
        print("You lost the chance!😔")
        compwin+=1
        chances-=1
        something = f"You are left with {chances} chances"
        print("")
        print(something)

    elif choice=="p" and rand=="s": # REverse
        print("You Won the chance!😇")
        hmwin+=1
        chances-=1
        something = f"You are left with {chances} chances"
        print("")
        print(something)

    elif choice=="s" and rand=="sc": #Straight
        print("You won the chance!😇")
        hmwin+=1
        chances-=1
        something = f"You are left with {chances} chances"
        print("")
        print(something)

    elif choice=="sc" and rand=="s": # REverse
        print("You lost the chance!😔")
        compwin+=1
        chances-=1
        something = f"You are left with {chances} chances"
        print("")
        print(something)






    elif choice=="p" and rand=="sc":
        print("You lost the chance!😔")
        compwin+=1
        chances-=1
        something = f"You are left with {chances} chances"
        print("")
        print(something)

    elif choice=="sc" and rand=="p":
        print("You Won the chance!😇")
        hmwin+=1
        chances-=1
        something = f"You are left with {chances} chances"
        print("")
        print(something)







    elif choice=="s" and rand=="p":
        print("You lost the chance!😔")
        compwin+=1
        chances+=1
        something = f"You are left with {chances} chances"
        print("")
        print(something)

    elif choice=="p" and rand=="s":
        print("You won the chance!😇 ")
        compwin+=1
        chances+=1
        something = f"You are left with {chances} chances"
        print("")
        print(something)
    
    
os.system('cls')
x = 3
y = 0
while x > y:
    os.system('cls')
    print("Getting your output ...\\")
    time.sleep(0.3)
    os.system('cls')
    print("Getting your output .../")
    time.sleep(0.3)
    os.system('cls')
    print("Getting your output ...|")
    time.sleep(0.3)
    os.system('cls')
    print("Getting your output ...")
    time.sleep(0.3)
    y += 3
if compwin>hmwin:
    xyz = f"Your score is {hmwin} \nComputer's score is {compwin}"
    print('Sorry! You lost the game 😔')
    print("")
    print(xyz)
elif hmwin>compwin:
    xyz = f"Your score is {hmwin}\nComputer's score is {compwin}"
    print('Congratulations! You won the game 😇👍')
    print("")
    print(xyz)
