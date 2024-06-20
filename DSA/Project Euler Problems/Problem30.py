def check_self_behaviour(num,pow):
    return num == sum([int(elem)**pow for elem in str(num)])
    
final_ans = 0
for i in range(2,1000000):
    if check_self_behaviour(i,5):
        final_ans += i
print(final_ans)