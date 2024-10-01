package AmazonPractice.Graphs;

public class ratInAMazeGraphs {
    static int N = 0;
    public static void main(String args[]){
        int maze[][] = { { 1, 0, 0, 0 },
                         { 1, 1, 0, 1 },
                         { 0, 1, 0, 0 },
                         { 1, 1, 1, 1 }};
        N = maze.length;
        solveMaze(maze);
    }

    static void solveMaze(int maze[][]){
        int soln[][] = new int[N][N];

        if(solveMazeUtil(maze,soln,0,0) == false){
            System.out.println("Cant reach end");
            return;
        }

        printSoln(soln);
    }

    static void printSoln(int[][] soln){
        for(int i=0;i<soln.length;i++){
            for(int j=0;j<soln.length;j++){
                System.out.print(soln[i][j]+" ");
            }
            System.out.println();
        }
    }

    static boolean solveMazeUtil(int maze[][], int soln[][], int x, int y){
        if(x==N-1 && y==N-1 && maze[x][y]==1){
            soln[x][y] = 1;
            return true;
        }

        if(isValid(maze,x,y)){
            if(soln[x][y] == 1) return false;

            soln[x][y] = 1;

            if(solveMazeUtil(maze, soln, x+1, y))
                return true;

            if(solveMazeUtil(maze, soln, x, y+1))
            return true;

            if(solveMazeUtil(maze, soln, x-1, y))
                return true;

            if(solveMazeUtil(maze, soln, x, y-1))
            return true;

            soln[x][y] = 0;
            return false;
        }
        return false;
    }

    static boolean isValid(int maze[][],int x, int y) {
        if(x>=0 && y>=0 && x<N && y<N && maze[x][y]!=0) return true;
        return false;
    }
}
