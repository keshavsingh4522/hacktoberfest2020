'''def search(arr,n,x):
    for i in range(0,n):
        if(arr[i]==x):
            return i
    return -1
arr =[12,23,34,55,66,78,90]
x=9
n= len(arr)

'''function call'''

result = search(arr,n,x)
if(result == -1):
    print("the element not found")
else:
    print("the element is found at index", result)
'''


