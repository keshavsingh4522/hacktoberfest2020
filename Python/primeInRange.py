start = int(input('enter lower limit of the range='))
end = int(input('enter upper limit of the range='))

for i in range(start, end + 1):
    if i > 1:
        for j in range(2, i):
            if i % j == 0:
                break
        else:
            print(i)
