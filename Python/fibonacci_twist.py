def check_prime(num):
    if num > 1:
        for i in range(2, num // 2 + 1):
            if (num % i) == 0:
                return False
        else:
            return True
    else:
        return False


# Program to display the Fibonacci sequence up to nth term
n = int(input("How many terms? "))

n1, n2 = 1, 1  # first two terms
count = 0

# check if the number of terms is one
if n == 1:
    print("Fibonacci sequence upto", n, ":")
    print(n1)

# generate fibonacci sequence
else:
    print("Fibonacci sequence:")
    while count < n:
        if not check_prime(n1) and n1 % 5 != 0:
            print(n1, end=' ')
        else:
            print(0, end=' ')
        nth = n1 + n2
        # update values
        n1 = n2
        n2 = nth
        count += 1
