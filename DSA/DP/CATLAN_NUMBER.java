/*
PROBLEM STATEMENT:

1. You are given a number n.
2. You are required to find the value of nth catalan number.
C0 -> 1
C1 -> 1
C2 -> 2
C3 -> 5
..
Cn -> C0.Cn-1 + C1.Cn-2 + .. + Cn-2.C1 + Cn-1.C0

*/

/*
CONSTRAINTS:
0 <= n <= 15
*/

/*   CODE */

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[]dp = new int[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int left=0;
            int right = i-1;
            while(left<=i-1){
                dp[i] += dp[left]*dp[right];
                left++;
                right--;
            }
        }
        System.out.println(dp[n]);
    }

}

/*  
SAMPLE INPUT :

4
*/

/*
SAMPLE OUTPUT :
14

*/
