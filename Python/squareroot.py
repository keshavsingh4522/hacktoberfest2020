
# Python Program to calculate the square root

num = float(input('Enter a number:'))

num_sqrt = num ** 0.5
num_sqrt = f"{num_sqrt:g}" #Throw out trailing zeros and extra decimals

num = f"{num:g}" #Throw out trailing zeros and extra decimals

print('The square root of ', num, ' is ', num_sqrt)
