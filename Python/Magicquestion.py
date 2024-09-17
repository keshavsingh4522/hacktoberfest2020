s = input().lower().split()
stop = ['a','and','the','an','this','is','in','was','that','are','were']
s1 = [i for i in s if i not in stop]
def magic(s):
    for i in range(int(len(s)/2)):  #0 to n/2
        if i%2==0 and s[i]<s[len(s)-1-i]:
            pass
        elif i%2 == 1 and s[i]>s[len(s)-1-i]:
            pass
        else:
            return False
    else:
        return True
def convertmagic(s):
    for i in range(int(len(s)/2)):  #0 to n/2
        if i%2==0 and s[i]<s[len(s)-1-i]:
            pass
        elif i%2 == 1 and s[i]>s[len(s)-1-i]:
            pass
        else:
            high = 0
            if s[i] > s[len(s) - 1 -i]:
                high = i
            else:
                high = len(s)-i-1
            return (s[:high] + s[high+1:])
magicWords = []
for i in s1:
    if magic(i):
        magicWords.append(i)
    else:
        s = i
        while (magic(s) == False):
            s1 = convertmagic(s)
            s = s1
            if magic(s):
                magicWords.append(s)
m = len(magicWords[0])
for i in magicWords:
    if len(i)<m:
        m = len(i)
final = [i[:m] for i in magicWords]
matrix = []
for i in range(len(final)):
    matrix.append([])
    for j in final[i]:
        matrix[i].append(j)
def rotate(arr, m):
    mrr = arr.copy()
    arr = tuple(arr)
    n = m-1
    for i in range(m):
        for j in range(m):
            a = arr[i][j]
            if j == 0 and 0<=i<=n-1:
                mrr[i+1][j] = a
            elif i == n and 0<=j<=n-1:
                mrr[i][j+1] = a
            elif j == n and 1<=i<=n:
                mrr[i-1][j] = a
            elif i == 0 and 1<=j<=n:
                mrr[i][j-1] = a
        #print(*mrr, sep = '\n')
        print('\n')
        print(*arr, sep = '\n')
        print('\n')

    return mrr
print(*rotate(matrix,m)) 
 dont read this
