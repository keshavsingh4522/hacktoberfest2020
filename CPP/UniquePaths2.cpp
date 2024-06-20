/*int path(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &ob)
    {
        if(ob[i][j])
            return 0;
        if(i==0 and j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up=path(i-1,j,dp,ob);
        int left=path(i,j-1,dp,ob);
        
        return dp[i][j]=up+left;
    }*/
    int uniquePathsWithObstacles(vector<vector<int>>& ob) 
    {
        int m=ob.size();
        int n=ob[0].size();
        if(ob[0][0]==1)
            return 0;
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0 and i==0)
                    continue;
                if(ob[i][j])
                    continue;
                if(i>0)
                    dp[i][j]+=dp[i-1][j];
                if(j>0)
                    dp[i][j]+=dp[i][j-1];
                
            }
        }
        
        return dp[m-1][n-1];
        
    }
