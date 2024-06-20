// A Dynamic Programming based 
// solution for 0-1 Knapsack problem 
#include <bits/stdc++.h> 
  
// A utility function that returns 
// maximum of two integers 
int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 
  
// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
     
    int dp[W + 1]; 
    memset(dp, 0, sizeof(dp));
    
    // Build table dp[] in bottom up manner 
    for (int i = 0; i < n; i++) { 
        for (int j = W; j >= wt[i]; j--) { 
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
        } 
    } 
  
    return dp[W]; 
} 
  
int main() 
{ 
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    printf("%d", knapSack(W, wt, val, n)); 
    return 0; 
} 
