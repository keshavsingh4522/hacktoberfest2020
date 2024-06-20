def checkTerm(n):
    num = 1 
    dem = 2

    for i in range(n-1):
        num = dem*2 + num
        num,dem = dem,num

    num = dem + num
    return len(str(num)) > len(str(dem))

ans = 0 
for i in range(1,1001):
    if checkTerm(i):
        ans += 1
print(ans)