n = 1000000
# n = 100
prime = [True for i in range(n+1)]
p = 2
while (p * p <= n):
    if (prime[p] == True):
        for i in range(p * p, n+1, p):
            prime[i] = False
    p += 1

primes = []

for i in range(2,n+1):
    if prime[i]:
        primes.append(i)

count = 0
ans = 0
for index,elem in enumerate(primes):   
    sum = 0
    temp = 0
    for i in range(index,len(primes)):
        sum += primes[i]
        temp +=1
        if sum > n:
            break
        if prime[sum]:
            if count < temp:
                ans = sum
                count = temp

print(ans,count)