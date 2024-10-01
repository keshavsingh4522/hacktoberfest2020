#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char startParen = '(';
    char endParen = ')';
    vector<string> ans;
    void generateStr(string add,int n,int open,int close)
    {   
        
        if (add.size() == 2*n)
        {   
            ans.push_back(add);
            return ;
        }
        if (open<n)
        generateStr(add+startParen,n,open+1,close);
        if (close<open)
        generateStr(add+endParen,n,open,close+1);
        
        
    }
    
    vector<string> generateParenthesis(int n) {
        generateStr("",n,0,0);
        return ans;
    }
};