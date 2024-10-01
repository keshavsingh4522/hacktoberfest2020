# Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

# In other words, return true if one of s1's permutations is the substring of s2.

 

# Example 1:

# Input: s1 = "ab", s2 = "eidbaooo"
# Output: true
# Explanation: s2 contains one permutation of s1 ("ba").
# Example 2:

# Input: s1 = "ab", s2 = "eidboaoo"
# Output: false
from collections import Counter
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        slidingWindow = len(s1)
        s1Counter = Counter(s1)
        
        for i in range(len(s2)-slidingWindow+1):
            s2Counter = Counter(s2[i:i+slidingWindow])
            if s2Counter == s1Counter:
                return True
            
        return False