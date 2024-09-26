import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] values = new int[n];
        int[] weights = new int[n];
        for(int i = 0 ; i < n ; i++){
            values[i] = sc.nextInt();
        }
        for(int i = 0 ; i < n ; i++){
            weights[i] = sc.nextInt();
        }
        int cap = sc.nextInt();
    int[][] dp = new int[n+1][cap+1];
    for(int i = 1 ; i <= n ;i++ )
    {
        for(int j = 1 ; j <=cap ; j++)
        {
           dp[i][j] = dp[i-1][j] ;
           if( j >= weights[i-1]){
               if(dp[i-1][j-weights[i-1]] + values[i-1] > dp[i][j])
               {
                   dp[i][j] = dp[i-1][j-weights[i-1]] + values[i-1] ;
               }
           }
        }
    }
    System.out.println(dp[n][cap]);
}

}
