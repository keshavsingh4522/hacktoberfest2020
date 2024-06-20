from itertools import permutations
import math

def check_prime(num):
    if num == 1:
        return False
    elif num == 2:
        return True
    else:
        for i in range(2,int(math.sqrt(num))+1):
            if num%i == 0:
                return False
        return True

data = []

for i in range(1,10):
    num = i
    temp = [str(elem) for elem in range(1,num+1)]
    for check in permutations(temp):
        num = ''.join(list(check))
        if check_prime(int(num)):
            data.append(int(num))

print(max(data))