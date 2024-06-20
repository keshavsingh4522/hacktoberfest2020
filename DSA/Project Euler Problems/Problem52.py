import copy

def checkproperty(n):
    a = set()
    for i in range(1,7):
        num = n*i
        check = [elem for elem in str(num)]
        check.sort()
        a.add(tuple(copy.deepcopy(check)))

    return len(a) == 1

i = 1 
while True: 
    if checkproperty(i):
        print(i)
        break
    i = i + 1
