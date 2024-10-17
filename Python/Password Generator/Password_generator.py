import random
import string

def generate_password(length=8):
    uppercase_letters = string.ascii_uppercase
    lowercase_letters = string.ascii_lowercase
    digits = string.digits
    special_characters = string.punctuation

    all_characters = uppercase_letters + lowercase_letters + digits + special_characters
    password = ''.join(random.choice(all_characters) for _ in range(length))

    return password

length = int(input("Enter the password length: "))
generated_password = generate_password(length)
print(f"Generated password: {generated_password}")
