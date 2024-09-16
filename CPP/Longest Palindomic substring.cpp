//longestPalindrome Substring

#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int start=0,mx=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            start = i;
            mx =1;
        } 
        for(int i=0;i<n-1;i++) {
            if(s[i]==s[i+1]){
                dp[i][i+1]=1;
                mx=2;
                start = i;
            } 
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                int j=i+k-1;
                if(dp[i+1][j-1] && s[i]==s[j]){
                    dp[i][j]=1;
                    if(k>mx){
                        mx=k;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,mx);
    }

int main() {
	// your code goes here
	string s;
	cin>>s;
	cout<<longestPalindrome(s)<<endl;
	return 0;
}
