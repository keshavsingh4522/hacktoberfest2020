class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=s.size();
        if(n==0){return "";}
        
        // Using vector might NOT pass the large test, use array instead.
        //vector<vector<bool> > table(n,vector<bool>(n,false));
        
        bool table[1000][1000] = {false};
        
        int maxst=0;
        int maxlen=1;
         
        for (int i=0;i<n;i++){
            table[i][i]=true; 
            maxst=i;
            maxlen=1;
        }
        for (int i=0;i<n-1;i++){
            if (s[i]==s[i+1]){
                table[i][i+1]=true;
                maxst=i;
                maxlen=2;
            }
        }
         
        for (int len=3; len<=n;len++){
            for (int i=0;i<n-len+1;i++){
                int j=i+len-1;
                if (s[i]==s[j] && table[i+1][j-1]){
                    table[i][j]=true;
                    maxst=i;
                    maxlen=len;
                }
            }
        }
        return s.substr(maxst,maxlen);
    }
};
