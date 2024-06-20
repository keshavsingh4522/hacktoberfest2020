def count_right_angle(p):
    ans = 0 
    for i in range(1,p):
        for j in range(i+1,p):
            if p - i - j >0 and p - i - j >j:  
                c = p - i - j
                if i**2 + j**2 == c**2:
                    ans += 1
    return ans 


ans = 0 
count = 0
for i in range(1,1001):
    check = count_right_angle(i)
    if check > count:
        ans = i
        count = check
print(ans)