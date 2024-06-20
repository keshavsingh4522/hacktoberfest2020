// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

 

// Example 1:


// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:


 

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.

class Solution {
    bool check(vector<vector<char>>& board,int i,int j,int k)
    {
        for(int x=0;x<9;x++)
        {
            if(board[x][j]==char(k+'0'))
                return false;
            
            if(board[i][x]==char(k+'0'))
                return false;
        }
        int row=i-i%3;
        int col=j-j%3;
        for(int r=0;r<3;r++)
        {
            for(int c=0;c<3;c++)
            {
                if(board[row+r][col+c]==char(k+'0'))
                    return false;
            }
        }
        return true;
    }
    
    bool solveSudoku(vector<vector<char>>& board,int i,int j) {
        if(i==9)
            return true;
        if(j==9)
            return solveSudoku(board,i+1,0);
        if(board[i][j]!='.')
            return solveSudoku(board,i,j+1);
        for(int k=1;k<=9;k++)
        {
            if(check(board,i,j,k))
            {
                board[i][j]=char(k+'0');
                if(solveSudoku(board,i,j+1))
                    return true;
                board[i][j]='.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board,0,0);
    }
};