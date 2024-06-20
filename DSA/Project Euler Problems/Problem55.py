def checkpalindromic(num):
    i = 1
    newNum = num
    while i <= 50:
        
        newNum = newNum + int(str(newNum)[::-1])
        i = i + 1
        if str(newNum) == str(newNum)[::-1]:
            return True
    return False

ans = 0
for i in range(1,10000):
    if not checkpalindromic(i):
        ans += 1
print(ans)