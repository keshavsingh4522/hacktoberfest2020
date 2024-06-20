import math

def check_curious(num):
    sum = 0
    for i in str(num):
        sum += math.factorial(int(i))
    return sum == num

final_ans = 0
for i in range(3,1000000):
    if check_curious(i):
        final_ans += i
print(final_ans)