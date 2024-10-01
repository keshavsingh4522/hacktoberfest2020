import math
# Program make a simple calculator

# This function adds two numbers
def add(x, y):
    return x + y

# This function subtracts two numbers
def subtract(x, y):
    return x - y

# This function multiplies two numbers
def multiply(x, y):
    return x * y

# This function divides two numbers
def divide(x, y):
    return x / y


print("Select operation.")
print("1.Add")
print("2.Subtract")
print("3.Multiply")
print("4.Divide")
print("5-Square Root")
print("6-sine")
print("7-cosine")
print("8-tangent")

while True:
    # take input from the user
    choice = input("Enter choice(1/2/3/4/5/6/7/8): ")

    # check if choice is one of the four options
    if choice in ('1', '2', '3', '4'):
        num1 = float(input("Enter first number: "))
        num2 = float(input("Enter second number: "))

        if choice == '1':
            print(num1, "+", num2, "=", add(num1, num2))

        elif choice == '2':
            print(num1, "-", num2, "=", subtract(num1, num2))

        elif choice == '3':
            print(num1, "*", num2, "=", multiply(num1, num2))

        elif choice == '4':
            print(num1, "/", num2, "=", divide(num1, num2))
        
        # check if user wants another calculation
        # break the while loop if answer is no
        next_calculation = input("Let's do next calculation? (yes/no): ")
        if next_calculation == "no":
          break

    elif(choice == '5'):
        x = int(input("Enter the Number"))
        print("square root of number is:",math.squareroot(x))
    
    elif(choice == '6'):
        x = int(input("Enter your Number: "))
        print("The sin function of your number is",math.sin(x))
    
    elif(choice == '7'):
        x = int(input("Enter your Number: "))
        print("The cos function of your number is",math.cos(x))

    elif(choice == '8'):
        x = int(input("Enter your Number: "))
        print("The Tan function of your number is",math.tan(x))
    
    else:
        print("Invalid Input")
