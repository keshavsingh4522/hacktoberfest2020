class Solution {
public:
    int palindrome_check(string s, int st, int e)
        {
            
            if (st == e) 
                return 1; 
  
    
             if (s[st] != s[e]) 
                return 2;
   
            if (st < e + 1) 
                return palindrome_check(s, st + 1, e - 1); 
  
            return 1;
        }
    int removePalindromeSub(string s) {
        
        int st=0;
        if(s.length()==0)
            return 0;
        
        int e= s.length()-1;
        int ctr=0;
                
        
         ctr+=palindrome_check(s, st, e);
        return ctr;
    }
    
   
};
