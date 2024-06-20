# just change Add to sum two numbers wether in float or int
num1 = 15.0
num2 = 12.0

# change Add to sum 
sum1 = num1 + num2 
# To add two float numbers with significant digits
num3 =112.654
num4=624.987
sum2 =num3 + num4 
#To round of number in integers
print(round(sum2))
#To round the number to it's nearest integer less than or equal to that argument’s value 
import math
print(math.floor(sum2))
#To round the number to it's nearest integer greater than or equal to that argument’s value 
print(math.ceil(sum2))

#you can truncate or set upto which decimal place you want output
# Like for truncate up to 2 decimal places
example:{
float  = 2.154327
format_float = "{:.2f}".format(float)
print(format_float)}

#else just print sum as mentioned below

print("Sum of {0} and {1} is {2}" .format(num1, num2, sum)) 

