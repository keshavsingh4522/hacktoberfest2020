import math

def check_prime(num):
    if num == 1 : 
        return False
    elif num == 2:
        return True
    else:
        for i in range(2,int(math.sqrt(num) + 1)):
            if num%i == 0:
                return False
        return True

def check_conjucature(num):
    for i in range(1,num):
        if check_prime(i):
            temp = num - i
            for j in range(1,temp):
                if 2*j*j == temp:
                    return True
    return False

i = 2
while True:
    if i%2 != 0 and not check_prime(i) and not check_conjucature(i):
        print(i)
        break
    i+=1
