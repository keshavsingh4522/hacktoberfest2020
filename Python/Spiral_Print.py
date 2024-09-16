#For a given two-dimensional integer array/list of size (n x m), print it in a spiral form. That is, you need to print in the order followed for every iteration:

from sys import stdin

def spiralPrint(mat, nRows, mCols):
    loop=nRows
    if loop%2!=0:
        loop+=1
    for i in range(loop//2):
        for j in range(i,mCols-i):
            print(mat[i][j],end=" ")
        for k in range(1+i,nRows-i):
            print(mat[k][j],end=" ")
        for l in range(mCols-2-i,-1+i,-1):
            print(mat[k][l],end=" ")
        for p in range(nRows-2-i,0+i,-1):
            print(mat[p][l],end=" ")

#Taking Input Using Fast I/O
def take2DInput() :
    li = stdin.readline().rstrip().split(" ")
    nRows = int(li[0])
    mCols = int(li[1])
    
    if nRows == 0 :
        return list(), 0, 0
    
    mat = [list(map(int, input().strip().split(" "))) for row in range(nRows)]
    return mat, nRows, mCols

#main
t = int(stdin.readline().rstrip())

while t > 0 :

    mat, nRows, mCols = take2DInput()
    spiralPrint(mat, nRows, mCols)
    print()

    t -= 1
