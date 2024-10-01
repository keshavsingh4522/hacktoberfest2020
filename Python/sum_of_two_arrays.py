def sum(arr1,arr2):
    len1=len(arr1)
    len2=len(arr2)
    arr=[0 for i in range(max(len1, len2)+1)]
    sum=0
    carry=0
    i = len1-1
    j=len2-1
    k = len(arr)-1
    
    while(i>=0 and j>=0):
        sum = arr1[i]+arr2[j]+carry
        arr[k] = sum%10
        carry = sum//10
        i-=1
        j-=1
        k-=1
        
    while(i>=0):
        sum = arr1[i]+carry
        arr[k] = sum%10
        carry = sum//10
        i-=1
        k-=1
        
    while(j>=0):
        sum = arr2[j]+carry
        arr[k] = sum%10
        carry = sum//10
        j-=1
        k-=1

    arr[0] = carry
    
    return arr

m=int(input())
arr1=[int(ele) for ele in input().split()]
n=int(input())
arr2=[int(ele) for ele in input().split()]
ans = sum(arr1,arr2)
print(*ans)
