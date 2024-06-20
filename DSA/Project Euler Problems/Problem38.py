import string

def find_pandigital(num):
    ans = ""
    temp = string.digits
    i = 1
    while len(ans) < 9:
        check = num*i
        ans += str(check)
        i += 1
    if len(ans) == 9:
        for elem in temp: 
            if elem not in ans and elem != '0':
                return False
        return int(ans)
    return False


data = []   
for i in range(1,100000):
    if find_pandigital(i):
        data.append(find_pandigital(i))
print(max(data))