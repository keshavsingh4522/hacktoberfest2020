from math import sqrt
 
 
def isPrime(n):
 
    # Corner case
    if (n <= 1):
        return False
 
    # Check from 2 to sqrt(n)
    for i in range(2, int(sqrt(n))+1):
        if (n % i == 0):
            return False
 
    return True
 
 
# Driver Code
if isPrime(11):
    print("true")
else:
    print("false")
