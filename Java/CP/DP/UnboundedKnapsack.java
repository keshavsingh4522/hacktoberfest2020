import java.io.*;
import java.util.*;

public class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            String line1[] = in.readLine().trim().split("\\s+");
            int N = Integer.parseInt(line1[0]);
            int W = Integer.parseInt(line1[1]);
            String line2[] = in.readLine().trim().split("\\s+");
            int val[] = new int[N];
            for(int i = 0;i < N;i++)
                val[i] = Integer.parseInt(line2[i]);
            String line3[] = in.readLine().trim().split("\\s+");
            int wt[] = new int[N];
            for(int i = 0;i < N;i++)
                wt[i] = Integer.parseInt(line3[i]);
                
            Solution ob = new Solution();
            System.out.println(ob.knapSack(N, W, val, wt));
        }
    }
}

// Implementation of the problem (recursive solution) starts here:

class Solution{
    static int[][] dp;
    static int helper(int W, int[] val, int[] wt, int n) {
        if(W==0 || n == -1) return 0;
        if(dp[n][W]!=-1) return dp[n][W];
        int res = 0;
        // not taking
        res = Math.max(helper(W,val,wt,n-1),res);
        // taking
        if(wt[n]<=W) res = Math.max(helper(W-wt[n],val,wt,n)+val[n],res);
        return dp[n][W] = res;
    }
    static int knapSack(int N, int W, int val[], int wt[])
    {
         dp = new int[N][W+1];
         Arrays.stream(dp).forEach(a -> Arrays.fill(a,-1));
         return helper(W,val,wt,N-1);
    }
}
