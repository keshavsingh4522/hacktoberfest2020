import java.io.*;
import java.util.*;

public class sudoku {
    public void main(String[] args) throws IOException {
        char[][] board = new char[9][9];
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 9; i++) {
            board[i] = in.readLine().toCharArray();
        }
        solve(board);
    }
    static boolean solve(char[][] board){
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isvalid(board,i,j,c)){
                            board[i][j]=c;
                            if(solve(board)==true){return true;}
                            else{board[i][j]='.';}
                        }
                        
                    }
                      return false; 
                }
                
            }
        }
      return true;
    } 
    static boolean isvalid(char[][]board, int row,int  col, char c){
        for(int i=0;i<9;i++){
            if( board[row][i]==c){return false;}
            if( board[i][col]==c){return false;}
            if(board[3*(row/3) +i/3][3*(col/3)+i%3]==c){return false;}
        }
        
        return true;     
    }
}
