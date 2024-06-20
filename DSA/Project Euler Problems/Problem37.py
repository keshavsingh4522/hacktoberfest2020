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

def truncatable_prime(num):
    numbers = set()
    string = str(num)
    for i in range(len(string)):
        numbers.add(int(string))
        string = string[1:]
    string = str(num)
    for i in range(len(string)):
        numbers.add(int(string))
        string = string[:-1]


    for elem in numbers:
        if not check_prime(elem):
            return False
    return True


ans ,count,i= 0,0,10
while count!=11:
    if truncatable_prime(i):
        ans += i
        count += 1
    i +=1
print(ans)
    
