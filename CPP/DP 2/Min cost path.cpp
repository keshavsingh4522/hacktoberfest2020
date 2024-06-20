/*
Min Cost Path
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.
 
Input format :
The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' 
respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.
Output format :
Print the minimum cost to reach the destination.

Constraints :
1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec

Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1

Sample Output 1 :
13


Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200

Sample Output 2 :
76


Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7

Sample Output 3 :
18
*/

#include<climits>
#include<vector>

int minCostPath(int **input, int m, int n) {
    
    vector<vector<int>> dp(m, vector<int> (n, -1));
    
    dp[0][0] = input[0][0];
    
    for(int i = 0, j = 1; j < n; j++) {
			dp[i][j]  = dp[i][j - 1] + input[i][j]; 
    }
    
    for(int i = 1; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int dp1 = INT_MAX;
            int dp2 = INT_MAX;
            int dp3 = INT_MAX;
            
            if(i >= 0 and j - 1 >= 0) {
                dp1 = dp[i][j - 1];
            }
            
            if(i - 1 >= 0 and j - 1 >= 0) {
                dp2 = dp[i - 1][j - 1];
            }
            
            if(i - 1 >= 0 and j >= 0) {
                dp3 = dp[i - 1][j];
            }
            
            dp[i][j] = input[i][j] + min(dp1, min(dp2, dp3));
        }
    }
    
    return dp[m - 1][n - 1];
    
}

// Dynamic Programming
// Time Complexity : O(mn)
// Auxillary Space : O(mn)


/******************************************************** Memoization *********************************************************
int minCost(int **input, vector<vector<int>>& memoize, int m, int n) {
    // base case
    if(m == 0 and n == 0) {
        return input[m][n];
    } else if(m < 0 or n < 0) {
        return INT_MAX;
    }
    
    if(memoize[m][n] != -1) {
        return memoize[m][n];
    }
    
    int answer = input[m][n] + min(minCost(input, memoize, m - 1, n - 1), min(minCost(input, memoize, m - 1, n), minCost(input, memoize, m, n - 1)));
	memoize[m][n] = answer;
    
    return memoize[m][n];
}

int minCostPath(int **input, int m, int n) {
    vector<vector<int>> memoize(m, vector<int> (n, -1));
    
    return minCost(input, memoize, m - 1, n - 1);
    
}

// Memoization
// Time Complexity : O(m*n);
// Auxillary Space : O(m*n);

*/

/******************************************************** Brute Force *********************************************************

int minCost(int **input, int m, int n) {
    // base case 
    if(m == 0 and n == 0) {
        return input[m][n];
    } else if(m < 0 or n < 0) {
        return INT_MAX;
    }
    
	return input[m][n] + min(minCost(input, m - 1, n - 1), min(minCost(input, m - 1, n), minCost(input, m, n - 1)));
    
}

int minCostPath(int **input, int m, int n) {
	//Write your code here
    return minCost(input, m - 1, n - 1);
}

// Brute Force
// Time Complexity : O(3^(mn))
// Auxillary Space : O(n)
*/
