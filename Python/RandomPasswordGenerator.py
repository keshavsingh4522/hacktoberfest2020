import string
import random
pass_len=int(input("Enter the length of the password:"))
def gen_pas(length):
    password="".join(random.choice(string.ascii_uppercase+string.ascii_lowercase+string.digits) for i in range(length))
    print("Your Random Password is:", password)
gen_pas(pass_len)
