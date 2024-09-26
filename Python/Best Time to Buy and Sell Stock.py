Solutions:

Brute force:

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        for i in range(len(prices)-1):
            for j in range(i+1,len(prices)):
                if max_profit < (prices[j]-prices[i]):
                    max_profit = (prices[j]-prices[i])
        return max_profit
        
        
        
        
  class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lowest_num = float("inf")
        max_profit = 0
        if len(prices)< 2:
            return 0
        for i in prices:
            lowest_num = min(lowest_num, i)
            max_profit = max(max_profit, (i-lowest_num))
        return max_profit
        
        
        
  class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices:
            max_val = 0
            min_val = max(prices)
            for i in range(len(prices)):
                if prices[i] < min_val:
                    min_val = prices[i]
                else:
                    max_val = max(max_val, prices[i] - min_val)
            return max_val
        else: 
            return 0
            
            
 class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if prices:
            max_profit = 0
            min_share = prices[0]
            for i in range(1,len(prices)):
                if prices[i] < min_share:
                    min_share = prices[i]
                if prices[i] > prices[i-1]:
                    max_profit = max(max_profit, prices[i] - min_share)
            return max_profit
        else:
            return 0

                
        
        class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = prices[0]
        res = 0
        for i in prices[1:]:
            if i < min_price:
                min_price = i
            res = max(res,i-min_price)
        return res
