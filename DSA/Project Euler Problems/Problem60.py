# Incomplete

import math
from itertools import combinations

def checkPrime(n):
    if n == 1:
        return False
    elif n == 2:
        return True
    else:
        for i in range(2, int(math.sqrt(n)) + 1):
            if n%i == 0:
                return False
    return True

def checkProperty(num):
    for i in range(len(num)):
        for j in range(len(num)):
            if i != j and not checkPrime(int(str(num[i]) + str(num[j]))):
                return False
    return True


prime = []
for i in range(1, 10**3 + 1):
    if checkPrime(i):
        prime.append(i)


for elem in combinations(prime,5):
    if elem[0] > 7:
        break
    if checkProperty(elem):
        print(elem)
        break