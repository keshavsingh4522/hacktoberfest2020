/*
Shortest Subsequence
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.

Note: The input data will be such that there will always be a solution.

Input Format :
The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.

Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V

Constraints:
1 <= |S| <= 1000 (|x| implies the length of the string x)
1 <= |V| <= 1000 

Time Limit: 1 second

Sample Input 1:
babab
babba

Sample Output 1:
3

Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.
*/

#include<vector>
#include<string>
#include<climits>
int solve(string s, string v) {
    // Write your code here
    int m = s.length();
    int n = v.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
    // If length of "v" == 0
    // Shortest Subsequence in S will be of length 1
    for(int i = 0; i < m + 1; i++) {
     	dp[i][0] = 1;   
    }
    
    // Since it is given that answer to the problem always exists
    // So length of "s" cannot be zero
    for(int j = 0; j < n + 1; j++) {
        dp[0][j] = 1001; 
    }
    
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
             char current = s[i - 1];
             auto it = v.substr(0,j).rfind(current);
             
             if(it != ULONG_MAX) {	
                 dp[i][j] = min(dp[i - 1][j], dp[i - 1][it] + 1);		
             } else {
                 dp[i][j] = 1;  
             }
        }
    }
    
    return dp[m][n];
}

// Time Complexity : O(mn^2)
// Auxillary Space : O(mn)
