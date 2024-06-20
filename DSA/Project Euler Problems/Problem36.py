def double_base_palindrome(num):
    binary_string = ""
    temp = num
    while temp!= 0:
        binary_string += str(temp%2)
        temp//=2
    return str(num) == str(num)[::-1] and binary_string == binary_string[::-1]

sum = 0
for i in range(1,1000000):
    if double_base_palindrome(i):
        sum += i
print(sum)