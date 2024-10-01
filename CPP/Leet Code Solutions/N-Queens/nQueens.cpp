// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 

// Example 1:


// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 9


class Solution {
    
public:
    int totalNQueens(int n) {
	vector<bool> col(n), diag(2*n-1), anti_diag(2*n-1);
	return solve(col, diag, anti_diag, 0);
    }
   
int solve(vector<bool>& col, vector<bool>& diag, vector<bool>& anti_diag, int row) {
	int n = size(col), count = 0;
    if(row == n) return 1;
	for(int column = 0; column < n; column++)           
		if(!col[column] && !diag[row + column] && !anti_diag[row - column + n - 1]){      
			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = true;    
			count += solve(col, diag, anti_diag, row + 1);                                
			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = false;     
		}                                
	return count;
}
};