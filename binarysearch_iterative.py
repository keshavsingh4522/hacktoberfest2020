def binarysearch_iterative(arr,ele):
    start=0
    end=len(arr)-1
    mid=0
    while (start<=end):
        mid=(start+end)//2
        if (arr[mid]==ele):
            return mid
        elif (arr[mid]<ele):
            start = mid+1
        else:
            end = mid-1
    return -1
            

arr=[int(ele) for ele in input().split()]
x=int(input())

index=binarysearch_iterative(arr,x)
if index!= -1:
  print(index)
else:
  print("element is not present in the given array")
