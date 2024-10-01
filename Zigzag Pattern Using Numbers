def Pattern(a, b):
    Zigzag = [[" " for i in range(b)] for j in range(a)]

    i, j = 0, 0
    num = 1
    down = False
    while j < b:
        Zigzag[i][j] = num
        if (i == a-1 or i == 0):
            down = not down
        if(down):
            i = i+1
        else:
            i = i-1
        j = j+1
        num = num + 1

    return Zigzag


def Printpattern(Zigzag, a, b):
    for i in range(0, a):
        for j in range(0, b):
            print(Zigzag[i][j], end=" ")
        print("\a")


a, b = list(map(int,input().split()))
Zigzag = Pattern(a, b)
Printpattern(Zigzag, a, b)
