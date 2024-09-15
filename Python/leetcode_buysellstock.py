class Solution(object):
    def maxProfit(self, prices):
        maxx= 0
        if len(prices)<2:
            return maxx
        min_so = prices[0]
        
        for i in range(1,len(prices)):
            if prices[i] < min_so:
                min_so = prices[i]
            elif maxx < abs(prices[i] - min_so):
                maxx = abs(prices[i] - min_so)
        return maxx
        
