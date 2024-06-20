import math

pairs = 0
for i in range(1,101):
    for j in range(1,i):
        if math.comb(i,j) > 1000000:
            pairs += 1

print(pairs)
