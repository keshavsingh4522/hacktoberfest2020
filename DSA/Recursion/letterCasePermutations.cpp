#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    
    vector<string> answer;
    
    void cases(string &s, int idx)
    {
        if(idx == s.size())
        {
            answer.push_back(s);

            return;
        }
        
        if(s[idx] >= '0' && s[idx] <= '9')
        {
            cases(s, idx+1);
        }

        if(s[idx] >= 'A' && s[idx] <= 'Z')
        {
            cases(s, idx + 1);

            s[idx] = s[idx] + 32;

            cases(s, idx + 1);

            s[idx] = s[idx] - 32;
        }

        if(s[idx] >= 'a' && s[idx] <= 'z')
        {
            cases(s, idx + 1);

            s[idx] = s[idx] - 32;

            cases(s, idx + 1);

            s[idx] = s[idx] + 32;
        }
        
    }
    vector<string> letterCasePermutation(string s) 
    {
        cases(s, 0);
        
        return answer;
    }
};