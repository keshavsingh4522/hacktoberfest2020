import math


def check_pentagonal(num):
    check = (math.sqrt(1 + 24*num)  + 1)/6
    return check == int(check)

i = 1
ans = False
while True:
    i+=1
    n = i*(3*i-1)/2
    for j in range(1,i):
        m = j*(3*j-1)/2
        if check_pentagonal(n-m) and check_pentagonal(n+m):
            print(n-m)
            ans = True
            break
    if ans:
        break