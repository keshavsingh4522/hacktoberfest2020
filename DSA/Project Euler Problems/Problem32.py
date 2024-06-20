def isPandigital(string):
    check = "".join(sorted(string))
    if check == "123456789":
        return True
    return False

def check_pandigital_Product(num):
    i = 1
    while i*i <= num:
        if num%i == 0 and isPandigital(str(num) + str(i) + str(num//i)):
            return True
        i+=1
    return False


sum = 0
for i in range(0,10000):
    if check_pandigital_Product(i):
        sum+=i
print(sum)
