#Number of sub-arrays with an odd sum
def countOddSum(ar,n):
    result = 0
    for i in range(n):
        val = 0
        for j in range(i, n):
            val = val + ar[j]
            if (val % 2 != 0):
                result +=1
    return (result)
n= int(input())

ar = list(map(int,input().split()))
print(str(countOddSum(ar,n)))