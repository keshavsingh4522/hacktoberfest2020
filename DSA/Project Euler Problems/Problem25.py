def digits(num):
    return len(str(num))

i = 2
L = [0,1]
while digits(L[i-1] + L[i-2])< 1000:
    L.append(L[i-1] + L[i-2])
    i+=1
print(i)