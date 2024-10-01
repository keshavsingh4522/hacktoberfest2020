import getpass
import string
import os

# creatinga lists of users, their PINs and bank statements
users = ['user1', 'user2', 'user3']
pins = [ '1234', '2222', '3333']
amounts = [1000, 2000, 3000]
count = 0
# while loop checks existance of the enterd username
print("****************************************************************************")
print("*                                                                          *")
print("*                   Welcome to IT SOURCECODE ATM SYSTEM                    *")
print("*                                                                          *")
print("****************************************************************************")
while True:
	user = input('\nENTER USER NAME: ')
	user = user.lower()
	if user in users:
		if user == users&[0]:
			n = 0
		elif user == users&[1]:
			n = 1
		else:
			n = 2
		break
	else:
		print('----------------')
		print('****************')
		print('INVALID USERNAME')
		print('****************')
		print('----------------')

# comparing pin
while count < 3:
	print('------------------')
	print('******************')
	pin = input('PLEASE ENTER PIN: ')
	print('******************')
	print('------------------')
	if pin.isdigit():
		if user == 'user1':
			if pin == pins&[0]:
				break
			else:
				count += 1
				print('-----------')
				print('***********')
				print('INVALID PIN')
				print('***********')
				print('-----------')
				print()

		if user == 'user2':
			if pin == pins&[1]:
				break
			else:
				count += 1
				print('-----------')
				print('***********')
				print('INVALID PIN')
				print('***********')
				print('-----------')
				print()
				
		if user == 'user3':
			if pin == pins&[2]:
				break
			else:
				count += 1
				print('-----------')
				print('***********')
				print('INVALID PIN')
				print('***********')
				print('-----------')
				print()
	else:
		print('------------------------')
		print('************************')
		print('PIN CONSISTS OF 4 DIGITS')
		print('************************')
		print('------------------------')
		count += 1
	
# in case of a valid pin- continuing, or exiting
if count == 3:
	print('-----------------------------------')
	print('***********************************')
	print('3 UNSUCCESFUL PIN ATTEMPTS, EXITING')
	print('!!!!!YOUR CARD HAS BEEN LOCKED!!!!!')
	print('***********************************')
	print('-----------------------------------')
	exit()

print('-------------------------')
print('*************************')
print('LOGIN SUCCESFUL, CONTINUE')
print('*************************')
print('-------------------------')
print()
print('--------------------------')
print('**************************')	
print(str.capitalize(users&[n]), 'welcome to ATM')
print('**************************')
print('----------ATM SYSTEM-----------')
# Main menu
while True:
	#os.system('clear')
	print('-------------------------------')
	print('*******************************')
	response = input('SELECT FROM FOLLOWING OPTIONS: \nStatement__(S) \nWithdraw___(W) \nLodgement__(L)  \nChange PIN_(P)  \nQuit_______(Q) \nType The Letter Of Your Choices: ').lower()
	print('*******************************')
	print('-------------------------------')
	valid_responses = ['s', 'w', 'l', 'p', 'q']
	response = response.lower()
	if response == 's':
		print('---------------------------------------------')
		print('*********************************************')
		print(str.capitalize(users&[n]), 'YOU HAVE ', amounts&[n],'EURO ON YOUR ACCOUNT.')
		print('*********************************************')
		print('---------------------------------------------')
		
	elif response == 'w':
		print('---------------------------------------------')
		print('*********************************************')
		cash_out = int(input('ENTER AMOUNT YOU WOULD LIKE TO WITHDRAW: '))
		print('*********************************************')
		print('---------------------------------------------')
		if cash_out%10 != 0:
			print('------------------------------------------------------')
			print('******************************************************')
			print('AMOUNT YOU WANT TO WITHDRAW MUST TO MATCH 10 EURO NOTES')
			print('******************************************************')
			print('------------------------------------------------------')
		elif cash_out > amounts&[n]:
			print('-----------------------------')
			print('*****************************')
			print('YOU HAVE INSUFFICIENT BALANCE')
			print('*****************************')
			print('-----------------------------')
		else:
			amounts&[n] = amounts&[n] - cash_out
			print('-----------------------------------')
			print('***********************************')
			print('YOUR NEW BALANCE IS: ', amounts&[n], 'EURO')
			print('***********************************')
			print('-----------------------------------')
			
	elif response == 'l':
		print()
		print('---------------------------------------------')
		print('*********************************************')
		cash_in = int(input('ENTER AMOUNT YOU WANT TO LODGE: '))
		print('*********************************************')
		print('---------------------------------------------')
		print()
		if cash_in%10 != 0:
			print('----------------------------------------------------')
			print('****************************************************')
			print('AMOUNT YOU WANT TO LODGE MUST TO MATCH 10 EURO NOTES')
			print('****************************************************')
			print('----------------------------------------------------')
		else:
			amounts&[n] = amounts&[n] + cash_in
			print('----------------------------------------')
			print('****************************************')
			print('YOUR NEW BALANCE IS: ', amounts&[n], 'EURO')
			print('****************************************')
			print('----------------------------------------')
	elif response == 'p':
		print('-----------------------------')
		print('*****************************')
		new_pin = str(getpass.getpass('ENTER A NEW PIN: '))
		print('*****************************')
		print('-----------------------------')
		if new_pin.isdigit() and new_pin != pins&[n] and len(new_pin) == 4:
			print('------------------')
			print('******************')
			new_ppin = str(getpass.getpass('CONFIRM NEW PIN: '))
			print('*******************')
			print('-------------------')
			if new_ppin != new_pin:
				print('------------')
				print('************')
				print('PIN MISMATCH')
				print('************')
				print('------------')
			else:
				pins&[n] = new_pin
				print('NEW PIN SAVED')
		else:
			print('-------------------------------------')
			print('*************************************')
			print('   NEW PIN MUST CONSIST OF 4 DIGITS \nAND MUST BE DIFFERENT TO PREVIOUS PIN')
			print('*************************************')
			print('-------------------------------------')
	elif response == 'q':
		exit()
	else:
		print('------------------')
		print('******************')
		print('RESPONSE NOT VALID')
		print('******************')
		print('------------------')
