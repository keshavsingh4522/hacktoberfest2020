# This Solution Needs Some time to run on Python(Depends on Your Machine)
def printseries(i):
    x = [i]
    while i > 1:
        if i%2==0:
            x.append(i//2)
            i = i//2
        else:
            x.append(3*i+1)
            i = 3*i +1
    return len(x)
#print(printseries(13))
ans,temp,num = 0,0,0
for i in range(2,1000000):
    temp = printseries(i)
    if temp>ans:
        ans = temp
        num = i
print(num)


