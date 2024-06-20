import math

def check_prime(num):
    if num == 1:
        return False
    elif num == 2:
        return True
    else:
        for i in range(2,int(math.sqrt(num) + 1)):
            if num%i == 0:
                return False
        return True

def check_sequence(sequence):
    num = [elem for elem in str(sequence[0])]
    num.sort()
    for elem in sequence:
        if not check_prime(elem):
            return False
        check = [el for el in str(elem)]
        check.sort()
        if num != check:
            return False
    return True


for i in range(1000,10000):
    for j in range(i+1,10000):
        k = 2*j - i
        if check_sequence([i,j,k]):
           print([i,j,k])
           
        

