def is_abundant(n):
    sum = 0
    for x in range(1, n//2 + 1):
        if n % x == 0:
            sum += x 
            n = n//x 
    return sum > n

abundant_numbers = list(x for x in range(1, 28123) if is_abundant(x))

sums = 0
for i in range(12, 28123):
    for abundant in abundant_numbers:
        if abundant >= i and is_abundant(i + abundant):
            sums += i
print(sums)