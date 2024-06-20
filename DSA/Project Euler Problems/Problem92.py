def checkArriving(num):
    new = num
    while new != 89 and new != 1:
        new = sum([int(elem)**2 for elem in str(new)])
    return new

ans = 0 
for i in range(1,10000000):
    if checkArriving(i) == 89:
        ans += 1
print(ans)