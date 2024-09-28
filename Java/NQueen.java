import java.util.*;
class NQueen 
{
    public static void main (String []Args)
    {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the value of N:");
        int n = in.nextInt();
        if(n>16)
        {
            System.out.println("INVALID INPUT");
        }
        else
        {
            int[][] arr = new int[n][n];
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    arr[i][j] = 0;
                }
            }
            System.out.println(n + " Queen's Problem: ");
            if(Nqueen(arr,0,n))
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        System.out.print(arr[i][j]+"\t");
                    }
                    System.out.println(" ");
                }
            }
        }       
    }
    public static boolean Nqueen(int arr[][],int x,int n)
    {
        if(x>=n)
        {
           return true;
        }
        for(int col =0; col<n;col++)
        {
            if(check(arr,x,col,n))
            {
                arr[x][col]=1;
            
                if(Nqueen(arr,x+1,n))
                {
                    return true;
                }
                arr[x][col]=0; 
            }//backtracking
          
        }
        return false;
    }
        
    public static boolean check(int arr[][] , int x , int y , int n)
    {
        for(int row =0;row<x;row++)
        {
            if(arr[row][y]==1)
            {
                return false;
            }
        }
        int row=x;
        int col = y;
        while(row>=0 && col>=0)
        {
            if(arr[row][col]==1)
            {
                return false;
            }
            row--;
            col--;
        }
        row = x;
        col = y;
        while(row>=0 && col<n)
        {
            if(arr[row][col]==1)
            {
                return false;
            }
            row--;
            col++;
        }
        return true;
    }
}