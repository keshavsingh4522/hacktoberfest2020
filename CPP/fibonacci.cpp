class Solution {
public:
    int fib(int n) {
        if(n<3)return n!=0;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        
        dp[1]=1;
        dp[2]=1;
        
        for(int i=3;i<=n;i++)dp[i]=dp[i-1]+dp[i-2];
        
        return dp[n];
    }
};
