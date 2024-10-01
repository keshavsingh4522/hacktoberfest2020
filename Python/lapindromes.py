t=int(input())
for i in range(t):
    n=input()
    len1 = len(n)
    if len1 % 2 == 0:
        b,c=n[:len1//2],n[len1//2:]
    else:
        b,c=n[:len1//2], n[len1//2+1:]
    if sorted(b) == sorted(c):
        print("YES")
    else:
        print("NO")
