import random

snakes={
    17:7,
    54:34,
    62:19,
    98: 79}

ladders={
    3:38,
    24:33,
    42:93,
    72: 84}


#start of game
print("\n###### Welcome to Snake & Ladder game ######\n")

#taking player input
print("\nEnter the name of player 1: ")
pname1 = input()

print("\nEnter the name of player 2: ")
pname2 = input()


p1 = p2 = 0
game = 0


while (game == 0):

	#PLAYER 1 stuff

	print("\n### " + pname1 + "'s Chance ###\n")

	print("Enter 0 for auto mode and 1 for manual mode: ")
	mode1 = int(input())

	if (mode1 == 1):
		num = int(input())
		p1 = p1 + num
		if (p1 >= 100):
			print("\n### " + pname1 + " Wins!! ###\n")
			game = 1
		else:
			print("Your new position is " + str(p1))

	elif (mode1 == 0):
		print("Roll or Quit: ")
		x = input()

		if (x == "roll"):
			num = random.randint(1, 6)
			print("You got a " + str(num))
			p1 = p1 + num
			if (p1 >= 100):
				print("\n### " + pname1 + " Wins!! ###\n")
				game = 1
			else:
				print("Your new position is " + str(p1))

		elif (x == "quit"):
			print("\n### " + pname2 + " Wins!! ###\n")
			break
	
	for key,value in snakes.items():
		if p1 == key:
			p1 = value
			print("Snake brought you to " + str(p1))

	for key,value in ladders.items():
		if p1 == key:
			p1 = value
			print("Ladder brought you to " + str(p1))


	#PLAYER 2 stuff
	
	print("\n### " + pname2 + "'s Chance ###\n")

	print("Enter 0 for auto mode and 1 for manual mode: ")
	mode2 = int(input())

	if (mode2 == 1):
		num = int(input())
		p2 = p2 + num
		if (p2 >= 100):
			print("\n### " + pname2 + " Wins!! ###\n")
			game = 1
		else:
			print("Your new position is " + str(p2))

	elif (mode2 == 0):
		print("Roll or Quit: ")
		x = input()

		if (x == "roll"):
			num = random.randint(1, 6)
			print("You got a " + str(num))
			p2 = p2 + num
			if (p2 >= 100):
				print("\n### " + pname2 + " Wins!! ###\n")
				game = 1
			else:
				print("Your new position is " + str(p2))

		elif (x == "quit"):
			print("\n### " + pname1 + " Wins!! ###\n")
			break
	
	for key,value in snakes.items():
		if p2 == key:
			p2 = value
			print("Snake brought you to " + str(p2))

	for key,value in ladders.items():
		if p2 == key:
			p2 = value
			print("Ladder brought you to " + str(p2))

print("### Thank You for Playing! ###")
