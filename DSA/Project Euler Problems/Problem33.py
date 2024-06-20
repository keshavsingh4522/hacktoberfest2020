def check_fraction(a,b):
    c = [elem for elem in str(a) ]
    d = [elem for elem in str(b)]
    if '0' in d or '0' in c:
        return False
    e = ""
    f = ""    
    for elem in c:
        if elem not in d:
            e += elem
    for elem in d:
        if elem not in c:
            f += elem
    if len(e)== 1 and len(f) == 1 and int(f) != '0':
        return a/b < 1 and a/b == int(e)/int(f)
    else:
        return False
   


for i in range(11,100):
    for j in range(11,100):
        if check_fraction(i,j):
            print(i,j)
# ans : 100