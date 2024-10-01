#Largest Sum Contiguous Subarray
arr=list(map(int,input().split()))
max_sum=min(arr)
window_sum=0

for i in range(len(arr)):
    window_sum=window_sum+arr[i]
    if(max_sum<window_sum):
        max_sum=window_sum
    if(window_sum<0):
        window_sum=0

print(max_sum)
