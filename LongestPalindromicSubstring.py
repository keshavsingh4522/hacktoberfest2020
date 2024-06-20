class Solution:
    def longestPalindrome(self, s: str) -> str:
        pal= ""
        palLen = 0
        
        
        for i in range(len(s)):
            l,r = i,i #odd length
            while l>=0 and r<len(s) and s[l]==s[r]:
                if (r-l+1)>palLen:
                    palLen = r-l+1
                    pal = s[l:r+1]
                l-=1
                r+=1
            
            l,r = i, i+1 #even length
            while l>=0 and r<len(s) and s[l]==s[r]:
                if (r-l+1)>palLen:
                    palLen = r-l+1
                    pal = s[l:r+1]
                l-=1
                r+=1
        return pal
