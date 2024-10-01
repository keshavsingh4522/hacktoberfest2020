r1=int(input("Enter the Row size for Matrix A: "))
c1=int(input("Enter the Column size for Matrix A: "))
r2=int(input("Enter the Row size for Matrix B: "))
c2=int(input("Enter the Column size for Matrix B: "))
A=[]
B=[]
R=[]
t=0
print("Enter elemnts for Matrix A")
for i in range(r1):
    l=[]
    for j in range(c1):
        t=int(input("Enter Element: "))
        l.append(t)
    A.append(l)
print("Enter elemnts for Matrix B")        
for i in range(r2):
    sl=[]
    l=[]
    for j in range(c2):
        t=int(input("Enter Element: "))
        sl.append(t+A[i][j])
        l.append(t)
    B.append(l)
    R.append(sl)
        
print("Result is\n")
print(R)
