

class Solution:
    def MissingNumber(self,array,n):
        # code here
        tt=n*(n+1)//2
        arrsum=sum(array)
        return tt-arrsum
