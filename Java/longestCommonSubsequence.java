class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int n= text1.length();
        int m=text2.length();
        int[][]dp=new int[n+1][m+1];
          for(int i=0;i<=n;i++)
              dp[i][0]=0;
          
         for(int j=0;j<=m;j++)
             dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          if(text1.charAt(i-1)!=text2.charAt(j-1))
                 dp[i][j]= Math.max(dp[i][j-1],dp[i-1][j] );
             else dp[i][j]=1+dp[i-1][j-1];
         }
        }
        return dp[n][m];
    }
}  
