
public class knightsTour{
    public static void main(String args[]){
        int mat[][] = new int[8][8];
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                mat[i][j] = -1;
        
        int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
        int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

        mat[0][0] = 0;

        if(solve(0,0,1,mat,dx,dy)){
            printSoln(mat);
        }
        else{
            System.out.println("No soln possible");
        }
    }

    static boolean solve(int x, int y, int steps, int mat[][], int dx[], int dy[]){
        if(steps == 64)
            return true;

        for(int i=0;i<8;i++){
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(isValid(xx,yy,mat)){
                mat[xx][yy] = steps;
                if(solve(xx,yy,steps+1,mat,dx,dy)) return true;
                else mat[xx][yy] = -1;
            }
        }
        return false;
    }

    static boolean isValid(int x,int y, int mat[][]){
        return (x>=0 && y>=0 && x<8 && y<8 && mat[x][y]==-1);
    }

    static void printSoln(int mat[][]){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                System.out.print(mat[i][j]+" ");
            }
            System.out.println();
        }
                
    }
}