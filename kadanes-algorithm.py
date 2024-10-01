class Solution:
    ##Complete this function
    #Function to find the sum of contiguous subarray with maximum sum.
    def maxSubArraySum(self,arr,N):
        ##Your code here
        s=0
        maxSum=arr[0]
        start=0
        poi=0
        end=0
        for i in range(N):
            s+=arr[i]
            if s>maxSum:
                start=poi
                end=i
                maxSum=s
            if s<0:
                s=0
                poi=i+1
        return maxSum
        #if find indices of sub-array
        # return [start,end]
