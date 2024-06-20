def sum_of_divisors(n):
    sum = 0
    for i in range(1,n//2 + 2):
        if n%i ==0:
            sum += i
    return sum

final_ans = 0
for i in range(2,10001):
    ans = sum_of_divisors(i)
    if sum_of_divisors(ans) == i and ans!=i:
        final_ans += i
print(final_ans)