def lcm(p, q):
   if p > q:
       grt = p
   else:
       grt = q

   while(True):
       if((grt % p == 0) and (grt % q == 0)):
           lcm = grt
           break
       grt += 1

   return lcm
   
n=int(input())
for t in range(n):
    l=[]
    x=int(input())
    k=int(input())
    v=x*k
    for i in range(x,v+1):
        for j in range(x,v+1):
            a=lcm(i,j)
            l.append(a)
    l=sorted(l)
    print(l)
    print(l[0],l[-1])