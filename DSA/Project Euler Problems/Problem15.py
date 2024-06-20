import math
def no_of_paths(sides):
    ans = math.factorial(2*sides)//(math.factorial(sides)**2)
    return ans
x = 20
print(no_of_paths(x))