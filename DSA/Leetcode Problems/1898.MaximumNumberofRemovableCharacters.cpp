class Solution {
public:
    bool isSubsequence(string t, string s) {
        if(s == t)
          return true;
        long long int  n = s.size();
        long long int  m = t.size();
        long long int  j = 0;
        for(long long int  i = 0; i < n; i++){
            if(t[j] == s[i])
            j++;
            if(j == t.size())
            return true;
        }
        return false;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        if(isSubsequence(p,s)==false){
            return 0;
        }
        int i=0;
        cout<<s<<" ";
        for(;i<removable.size();i++){
            int j=removable[i]%s.size();
            for(;j<s.size();j++){
                s[j]=s[j+1];
            }
            cout<<s<<" ";
            if(isSubsequence(p,s)==false){
                break;
            }
        }
        return i;
    }
};