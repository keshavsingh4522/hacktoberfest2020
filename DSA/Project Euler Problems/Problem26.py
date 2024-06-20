def cyclelength(num):
    prev = 1
    cycles = 0
    check = []
    while True:
        if prev in check:
            break
        check.append(prev)
        prev = (prev*10)%num
        cycles += 1
    return cycles

ans = 0
max_cycle_detected = 0
for i in range(1,1000):
    if max_cycle_detected < cyclelength(i):
        max_cycle_detected = cyclelength(i)
        ans = i
print(ans) 


