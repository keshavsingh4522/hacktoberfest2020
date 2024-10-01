class Solution {
public:
    bool isPallindrome(string str)
    {
        int n = str.size();
        
        for(int i=0;i<n/2;i++)
        {
            if(str[i]!=str[n-i-1])
                return false;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        unordered_map<string,int> m;
        vector<vector<int>> res;
        int n = words.size();
       
        for(int i=0;i<n;i++) 
        {
            m[words[i]] = i; //adding individual words with their corresponding indices
        }
        
        if(m.find("")!=m.end())// Case 1: if the input contains "" string
        {
            int blank_index = m[""];
            for(int i=0;i<n;i++)
            {
                
                if(i!=blank_index&&isPallindrome(words[i]))//Add indices of all those pallindromic strings 
                    // with that of "" string to res
                {
                    res.push_back({blank_index,i});
                    res.push_back({i,blank_index});
                }
            }
        }
        
        for(int i=0;i<n;i++)// Case 2: If string and its reverse both are present in the input
        {
            string str = words[i];
            reverse(str.begin(),str.end());
            
            if(m.find(str)!=m.end()&&i!=m[str])
                res.push_back({i,m[str]});
        }
        
        
        for(int i=0;i<n;i++)// Case 3: Tricky one!!
        {
            string str = words[i];
            
            for(int cut=1;cut<str.size();cut++)
            {
                string left = str.substr(0,cut);
                string right = str.substr(cut);
                
                if(isPallindrome(left))// Case 3a): If the left part of the string is pallindrome and 
                    // the reverse of right part exists in the input
                {
                    string s = right;
                    reverse(s.begin(),s.end());
                    if(m.find(s)!=m.end())
                    {
                        res.push_back({m[s],i});
                    }
                }
                
                if(isPallindrome(right))// Case 3b): If the right part of the string is pallindrome and 
                    // the reverse of left part exists in the input
                {
                    string s = left;
                    reverse(s.begin(),s.end());
                    if(m.find(s)!=m.end())
                    {
                        res.push_back({i,m[s]});
                    }
                }
            }
        }
        
        
        return res;
        
    }
};