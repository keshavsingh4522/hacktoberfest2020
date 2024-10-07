import tkinter as tk
import random
import string
import pyperclip
from tkinter import messagebox

def generate_password(length, use_lowercase, use_uppercase, use_numbers, use_symbols):
    char_set = ""  


    if use_lowercase:
        char_set += string.ascii_lowercase
    if use_uppercase:
        char_set += string.ascii_uppercase
    if use_numbers:
        char_set += string.digits
    if use_symbols:
        char_set += string.punctuation

    if not char_set:
        return "Select at least one option!"

    password = []
    if use_lowercase:
        password.append(random.choice(string.ascii_lowercase))
    if use_uppercase:
        password.append(random.choice(string.ascii_uppercase))
    if use_numbers:
        password.append(random.choice(string.digits))
    if use_symbols:
        password.append(random.choice(string.punctuation))

    password += random.choices(char_set, k=length - len(password))

    random.shuffle(password)
    return ''.join(password)

def generate():
    length = length_var.get()
    use_lowercase = lowercase_var.get()
    use_uppercase = uppercase_var.get()
    use_numbers = numbers_var.get()
    use_symbols = symbols_var.get()

    if length < 6:
        messagebox.showwarning("Weak Password", "Password length should be at least 6.")
        return

    password = generate_password(length, use_lowercase, use_uppercase, use_numbers, use_symbols)
    password_display.delete(0, tk.END)
    password_display.insert(0, password)
    update_strength()

def copy_to_clipboard():
    password = password_display.get()
    if password:
        pyperclip.copy(password)
        messagebox.showinfo("Copied", "Password copied to clipboard")
    else:
        messagebox.showwarning("No Password", "Generate a password first")

def check_password_strength(password):
    if len(password) < 8:
        return "Weak"
    elif len(password) < 12:
        return "Moderate"
    elif any(char.isdigit() for char in password) and any(char.isupper() for char in password):
        return "Strong"
    else:
        return "Moderate"

def update_strength():
    password = password_display.get()
    strength = check_password_strength(password)
    strength_label.config(text=f"Password Strength: {strength}")

root = tk.Tk()
root.title("Password Generator")
root.geometry("400x300")

label = tk.Label(root, text="Advanced Password Generator", font=("Arial", 16))
label.pack(pady=10)

length_label = tk.Label(root, text="Password Length:")
length_label.pack()
length_var = tk.IntVar(value=12)
length_slider = tk.Scale(root, from_=6, to=32, orient="horizontal", variable=length_var)
length_slider.pack()


lowercase_var = tk.BooleanVar(value=True)  
lowercase_check = tk.Checkbutton(root, text="Include Lowercase Letters", variable=lowercase_var)
lowercase_check.pack()

uppercase_var = tk.BooleanVar()
uppercase_check = tk.Checkbutton(root, text="Include Uppercase Letters", variable=uppercase_var)
uppercase_check.pack()

numbers_var = tk.BooleanVar()
numbers_check = tk.Checkbutton(root, text="Include Numbers", variable=numbers_var)
numbers_check.pack()

symbols_var = tk.BooleanVar()
symbols_check = tk.Checkbutton(root, text="Include Symbols", variable=symbols_var)
symbols_check.pack()

password_display = tk.Entry(root, font=("Arial", 12), width=30)
password_display.pack(pady=10)

generate_button = tk.Button(root, text="Generate Password", command=generate)
generate_button.pack(pady=10)

copy_button = tk.Button(root, text="Copy to Clipboard", command=copy_to_clipboard)
copy_button.pack(pady=5)

strength_label = tk.Label(root, text="Password Strength: ", font=("Arial", 12))
strength_label.pack(pady=5)

root.mainloop()
