def binary_search(arr, x):
    l = 0
    r = len(arr) - 1
    mid = 0
 
    while l <= r:
        mid = (r + l) 
        if arr[mid] < x:
            l = mid + 1
        elif arr[mid] > x:
            r = mid - 1
        else:
            return mid
    return -1
 
arr = [ 5, 8, 14, 19, 40 ]
x = 19

res = binary_search(arr, x)
 
if res != -1:
    print("Element is at index", str(res))
else:
    print("Element is not there in array")
