n=int(input())
i=1
# p=1
while i<=n:
    j=1
    spaces=1
    while spaces<=n-i:
        print(' ',end='')
        spaces=spaces+1
         # p=i
    j=i
    while (j>=1):
        print(j,end='')
        j=j-1

    j=2  
    while(j<=i):
        print(j,end='')
        j=j+1 #u forgot to decrease j each time
        #thus giving error


    print()
    i=i+1
