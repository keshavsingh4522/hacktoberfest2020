class Solution {
public:
    int longestSubstring(string s, int k) {
            //divide and conquer method
            int n= s.length();
            if(n==0 or n<k) return 0;
            if(k==1) return n;
            
            unordered_map<char,int>mpp;
            for(char c:s) mpp[c]++;
            
            
            int l=0;
            //this finds the first position were the element with count less than  k occurs
            while(l<n and mpp[s[l]]>=k)l++; 
            
            if(l>=n-1)  return l;//if l is the last character or the complete string is valid
            
            
            //the part before the lth character
            int l1= longestSubstring(s.substr(0,l),k);
            
            while(l<n and mpp[s[l]]<k) l++;// if there are more than one such character;
            
            // here i keep a check if l reaches end
            int l2= (l<n) ? longestSubstring(s.substr(l),k): 0;
            
            
            return max(l1,l2);
            
            
               
            
            
    }
};
