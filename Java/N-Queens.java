import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] chess = new int[n][n];
        
        printNQueens(chess, "", 0);
    }

    public static void printNQueens(int[][] chess, String qsf, int row) {
        if(row == chess.length)
        {
            System.out.println(qsf + ".");
            return;
        }
        
        for(int col = 0; col<chess[0].length; col++)
        {
            if(isQueenSafe(chess, row, col) == true)
            {
                chess[row][col]=1;
                printNQueens(chess, qsf + row + "-" + col + ", ", row+1);
                chess[row][col]=0;
            }
        }
        
    }
    public static boolean isQueenSafe(int[][] chess, int row, int col)
    {
        // top
        for(int i = row -1, j = col; i >= 0; i--)
        {
            if(chess[i][j] == 1)
            {
                return false;
            }
        }
        
        // left diagonal
        for(int i = row-1, j = col-1; i>=0 && j>=0; i--, j--)
        {
            if(chess[i][j] == 1)
            {
                return false;
            }
        }
        // right diagonal
        for(int i = row-1, j= col+1; i>=0 && j < chess[0].length; i--, j++)
        {
            if(chess[i][j] == 1)
            {
                return false;
            }
        }
        
        return true;
        
    }
}
