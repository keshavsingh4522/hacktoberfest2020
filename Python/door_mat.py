n, m = input().split()
n=int(n)
m=int(m)
count=1;
welcome="WELCOME"
welind=0
welstart=(m-7)//2
welend=welstart+7

lis = [[0 for i in range(m)] for j in range(n)]
rev=False

for i in range(0,n):
    if(i>n//2):
        rev=True
    if(rev):
        start=start+3
        end=end-3
    else:
        dupi=i+1
        value=3*(dupi+(dupi-1))
        start=((m-value)//2)-1
        end=(start+value)
        #print(start,end)
    
    for j in range(0,m):
        # if(i==n//2):
        #     s=(m-7)//2
        #     e=s+7
            # print(s,e)
            # if (j>=s and j<e):
            #     lis=[i][j]="z"
        if i==(n//2):
            if j>=welstart and j<welend:
                lis[i][j]=welcome[welind]
                welind+=1
                #pass
            else:
                lis[i][j]='-'        
        else:    
            
            if j>start and j<=end:
                if(count==1):
                    lis[i][j]="."
                    count=2
                elif(count==2):
                    lis[i][j]="|"
                    count=3
                elif(count==3):
                    lis[i][j]="."
                    count=1
            
            else:
                lis[i][j]="-"
for i in range(0,n):
    for j in range(0,m):
        print(lis[i][j],end="")
    print()
            

# Sample Input

# 9 27
# Sample Output

# ------------.|.------------
# ---------.|..|..|.---------
# ------.|..|..|..|..|.------
# ---.|..|..|..|..|..|..|.---
# ----------WELCOME----------
# ---.|..|..|..|..|..|..|.---
# ------.|..|..|..|..|.------
# ---------.|..|..|.---------
# ------------.|.------------