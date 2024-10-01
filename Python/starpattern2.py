def pattern(n):
    for i in range(1,2*(n+1)):
        if i <= n:
            for j in range(1,i+1):
                print("*",end="")
            print("\r")
        else:
            for j in range(1,2*n-i+1):
                print("*",end="")
            print("\r")

pattern(5)
