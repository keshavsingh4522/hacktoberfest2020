def factors(n):
    result = set()
    for i in range(1, int(n ** 0.5) + 1):
        div, mod = divmod(n, i)
        if mod == 0:
            result |= {i, div}
    return result


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


a = int(input("Input your first number: "))
b = int(input("Input your second number: "))

gf = gcd(a, b)
print(factors(gf))
