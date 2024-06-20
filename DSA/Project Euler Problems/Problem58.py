import math

def check_prime(num):
    if num == 1:
        return False
    elif num == 2:
        return True
    else:
        for i in range(2, int(math.sqrt(num) + 1)):
            if num%i == 0:
                return False

    return True



primes = 3
curr = 9
size = 2
while primes/(2*size + 1) > 0.10:
    size += 2
    for i in range(3):
        curr += size
        if check_prime(curr):
            primes += 1
    curr += size
print(size + 1)