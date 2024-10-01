#Encrypt Function
def encrypt(password):
    password_li = list(password)
    encrypted_password = ""
    for i in password_li:
        ascii_password_li = chr(ord(i) + 5)
        encrypted_password = encrypted_password + ascii_password_li
    print("Your encrypted password is: ")
    print(encrypted_password)
    
#decrypt Function
def decrypt(password):
    password_li = list(password)
    decrypted_password = ""
    for i in password_li:
        ascii_password_li = chr(ord(i) - 5)
        decrypted_password = decrypted_password + ascii_password_li
    print("Your decrypted password is: ")
    print(decrypted_password)

option_selected = input("You want to encrypt or decrypt: \n 1: Encrypt \n 2: Decrypt \n")

if int(option_selected )== 1 :
    password = input("Enter you password: ")
    encrypt(password)
else:
    password = input("Enter you encrypted password which was encrypted by this program only: ")
    decrypt(password)

