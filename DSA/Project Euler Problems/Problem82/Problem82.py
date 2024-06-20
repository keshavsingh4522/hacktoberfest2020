from queue import PriorityQueue


def checkboundary(i,j,n):
    return i >= 0 and i < n and j >= 0 and j < n


def findminSum(A):
    q = PriorityQueue()
    q.put((A[0][0],0,0))
    vis =  [[False for i in range(len(A))] for j in range(len(A))]
    vis[0][0] = True
    while not q.empty():
        curr,i,j = q.get()
        print(A[i][j],end=' ')
        if j == len(A)-1:
            # print(curr)
            break
        if checkboundary(i+1, j, len(A)) and not vis[i+1][j]:
            q.put((curr + A[i+1][j],i+1,j))
            vis[i+1][j] = True

        if checkboundary(i-1, j, len(A)) and not vis[i-1][j]:
            q.put((curr + A[i-1][j],i-1,j))
            vis[i-1][j] = True

        if checkboundary(i,j+1,len(A)) and not vis[i][j+1]:
            q.put((curr + A[i][j+1],i,j+1))
            vis[i][j+1] = True





A = [[131,673,234,103,18],
[201,96,342,965,150],
[630,803,746,422,111],
[537,699,497,121,956],
[805,732,524,37,331]]
# f = open("p081_matrix.txt")
# for elem in f.readlines():
#     A.append(list(map(int,elem.split(','))))
findminSum(A)
