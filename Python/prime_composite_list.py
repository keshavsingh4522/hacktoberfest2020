"""create a function with the name check_prime which takes a number as input and checks if the given number is prime or composite. The function returns 1 if the number is prime,0 if the number is composite and 0 otherwise.

create another function with the name prime_composite_list which takes a list of numbers and checks whether the numbers in the list are prime or composite. Include all th prime numbers in one list and all the composite numbers in another list. Create a 3rd list and include the list of prime numbers and the list of composite numbers in the 3rd list and return the 3rd list from this function. The third list should be a list of lists.

Note : use the function check_prime to find whether the number is prime or composite.

To test the code against your customized Input through console, please refer to the below instructions

The first line in the sample input is the count of numbers to be provided in the input list
The next few lines are the numbers to be included in the list provided one by one
"""






def prime_composite_list(inp):
    n = len(inp)
    a = []
    b = []
    c = [b, a]
    for i in range(0, n):
        p = inp[i]
        num = int(p)
        count = 0
        for i in range(1, num):
            if (num % i == 0):
                count += 1
        if (count > 1):
            a.append(p)
        else:
            b.append(p)
    return c


def check_prime(p):
    numb = p
    if (numb <= 1):
        return 1
    if (numb <= 3):
        return 1
    if (numb % 2 == 0 or numb % 3 == 0):
        return 0
    i = 5
    while (i * i <= numb):
        if (numb % i == 0 or numb % (i + 2) == 0):
            return 0
        i = i + 6
    return 1

    

if __name__ == '__main__':
    inp = []
    count = int(input())
    for i in range(count):
        inp.append(int(input()))
    print(check_prime(inp[1]))
    result = prime_composite_list(inp)
    print(result)
