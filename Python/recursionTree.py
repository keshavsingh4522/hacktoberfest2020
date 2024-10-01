def func(n):
    if (n>0):
        print(n)
        func(n-1)
        func(n-1)

n = int(input())
func(n)