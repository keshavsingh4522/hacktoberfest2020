def check_triangle_number(num):
    for i in range(1,num+1):
        if (i*(i+1))/2 == num:
            return True
    return False

f = open("words.txt",'r')
x = f.readlines()[0].split(',')
ans = 0
for elem in x:
    value = 0
    for char in elem: 
        if char != '\"':
            value += ord(char) - ord("A") + 1
    if check_triangle_number(value):
        ans += 1
print(ans)
    
        