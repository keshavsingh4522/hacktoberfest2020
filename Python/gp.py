# a simple program to find sum of GP (Geometric Progression) series.
import math

a = int(input("please enter the first no. of the series(a): "))
n = int(input("please enter the total no. of numbers in this series(n): "))
r = int(input("please enter the common ratio(r): "))

total = (a * (1 - math.pow(r, n ))) / (1- r)
tn = a * (math.pow(r, n - 1))

print("\nsum of GP (Geometric Progression) series = " , total)
