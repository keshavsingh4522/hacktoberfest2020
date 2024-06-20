check = 0
for i in range(1,101):
    for j in range(1,101):
        ans = [int(elem) for elem in str(i**j)]
        check = max(sum(ans),check)

print(check)