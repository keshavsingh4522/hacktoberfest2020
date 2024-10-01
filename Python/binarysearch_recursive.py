def binarysearch_recursive(arr,start,end ,x):
  if end>= start:
      mid=(start+end)//2
      if arr[mid]== x:
        return mid
      
      elif arr[mid]>x:
        return binarysearch_recursive(arr,start, mid-1,x)
      
      else:
        return binarysearch_recursive(arr,mid+1, end,x)
  
  else:
    return -1
  
  
arr= [int(ele) for ele in input().split()]
x=int(input())

index= binarysearch_recursive(arr,0,len(arr)-1 ,x)
if index!=-1:
  print(index)
 else:
  print("element is not present in the given array")
