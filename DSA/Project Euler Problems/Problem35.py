import math

def check_prime(num):
    if num == 1:
        return False
    elif num == 2:
        return True
    else:
        for i in range(2,int(math.sqrt(num)+1)):
            if num%i == 0:
                return False
    return True

def get_rotations(num):
    numbers = []
    check = str(num)
    for i in range(len(str(num))):
        check = check[1:] + check[0]
        numbers.append(int(check))
    for elem in numbers:
        if not check_prime(elem):
            return False
    return True

final_ans = 0

for i in range(1,1000000):
   if get_rotations(i):
       final_ans+=1

print(final_ans)
