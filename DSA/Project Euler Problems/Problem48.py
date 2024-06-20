sum = 0
for i in range(1,1001):
    sum += i**i
    sum = sum%10000000000
print(sum)
