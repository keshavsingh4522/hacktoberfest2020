import math

def check_prime(num):
    if num < 0 :
        return False
    elif num == 1:
        return False
    elif num == 2:
        return True
    else:
        for i in range(2,int(math.sqrt(num)+1)):
            if num%i == 0:
                return False
    return True

def check_producing_primes(a,b):
    ans = 0
    expr = b
    while check_prime(expr):
        ans +=1
        expr = ans*ans + a*ans + b
    return ans-1


max_n_value = 0
product = 0
curr_n_value = 0

for i in range(-1000,1001):
    for j in range(-1000,1001):
        curr_n_value = check_producing_primes(i,j)
        if max_n_value < curr_n_value:
            max_n_value = curr_n_value
            product = i*j
print(product)