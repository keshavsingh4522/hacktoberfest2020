n=int(input())
k = n
rev = 0
  
while(n > 0):
    
    a = n % 10
    rev = rev * 10 + a 
    n = n // 10
      
# print(rev) 

if(k==rev):
    print("true")
else:
    print("false")


n=int(input())
rev=0

k=n

while(n>0):
    a= n%10
    rev= rev*10+a
    n=n//10
    
if(rev==k):
    print("")
