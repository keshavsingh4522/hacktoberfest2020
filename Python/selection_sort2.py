import random
n = int(input())
A = []

for i in range(0, n):
    A.append(random.randint(0, 100))

for i in range(len(A)):
    min_idx = i
    for j in range(i+1, len(A)):
        if A[min_idx] > A[j]:
            min_idx = j
    A[i], A[min_idx] = A[min_idx], A[i]

print(A)
