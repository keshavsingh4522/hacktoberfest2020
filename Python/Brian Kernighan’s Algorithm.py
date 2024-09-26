def countSetBits(n):

    count = 0
    while (n):
        n &= (n-1)
        count+= 1 
    return count
 
i = 9
print(countSetBits(i)
