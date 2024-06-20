## Given Number : 28433x(2^7830457) + 1
def power(x, y, p) :
    res = 1   
    x = x % p
     
    if (x == 0) :
        return 0
 
    while (y > 0) :

        if ((y & 1) == 1) :
            res = (res * x) % p
 
    
        y = y >> 1
        x = (x * x) % p
         
    return res

# This code is contributed by Khushboogoyal499

print((power(2,7830457,10**10)*28433 + 1)%(10**10))