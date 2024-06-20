# Solution Takes 5-10 Minutes to Execute

def findPrimeFactors(num):
    primeFactors = set()
    while num%2 == 0:
        primeFactors.add(2)
        num//=2
    b = num//2 + 1
    for i in range(3,b,2):
        while num%i == 0:
            primeFactors.add(i)
            num//=i
    if num > 1:
        primeFactors.add(num)
    return primeFactors

i = 1


while True:
    a = findPrimeFactors(i)
    b = findPrimeFactors(i+1)
    c = findPrimeFactors(i+2)
    d = findPrimeFactors(i+3)
    if len(a) == 4 and len(b) == 4 and len(c) == 4 and len(d)==4:
        print(i,i+1,i+2,i+3)
        break
    i+=1
    print(i)

