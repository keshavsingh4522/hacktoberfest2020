from itertools import permutations

def check_unique_property(num):
    check = str(num)
    div = [2,3,5,7,11,13,17]
    for i in range(1,8):
        num = int(check[i:i+3])
        if num%div[i-1] != 0:
            return False
    return True


ans = 0
num = 9
temp = [str(elem) for elem in range(0,num+1)]
for check in permutations(temp):
    num = ''.join(list(check))
    if check_unique_property(int(num)):
        ans += int(num)


print(ans)
