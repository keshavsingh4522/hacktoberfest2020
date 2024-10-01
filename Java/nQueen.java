package AmazonPractice.Graphs;

public class nQueen{
    static int N = 4;
    static int ld[] = new int[30];
    static int rd[] = new int[30];
    static int cl[] = new int[30];

    public static void main(String args[]){
        int mat[][] = new int[N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                mat[i][j] = 0;
            }
        }

        if(solve(mat,0)){
            printSoln(mat);
        }
        else
            System.out.println("No solutions exist...");
    }

    static boolean solve(int mat[][], int col){
        if(col>=N) return true;

        for(int i=0;i<N;i++){
            if ((ld[i-col+N-1] != 1 && rd[i+col] != 1) && cl[i] != 1){
                mat[i][col] = 1;
                ld[i-col+N-1] = rd[i+col] = cl[i] = 1;

                if(solve(mat,col+1)) return true;

                mat[i][col] = 0;
                ld[i-col+N-1] = rd[i+col] = cl[i] = 0;
            }
        }
        return false;
    }

    static void printSoln(int mat[][]){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                System.out.print(mat[i][j]+" ");
            }
            System.out.println();
        }
    }
}