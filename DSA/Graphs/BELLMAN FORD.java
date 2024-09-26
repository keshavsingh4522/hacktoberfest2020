
/*
PROBLEM STATEMENT:


You are given 2 integers N and M , N is the number of vertices, M is the number of edges. You'll also be given ai, bi and wi where ai and bi represents an edge from a vertex ai to a vertex bi and wi respresents the weight of that edge.
Your task is to find the shortest path from source vertex (vertex number 1) to all other vertices.


*/

/*
CONSTRAINTS:

1<= N <= 10^4
1<= M <= 10^6
1<= ai, bi <= N
-1000 <= wi <= 1000
*/


/*

INPUT FORMAT:

First line contains two space separated integers,N and M. Then M lines follow, each line has 3 space separated integers ai, bi and wi.

*/

/*
OUTPUT FORMAT: 

Print the shortest distances from the source vertex (vertex number 1) to all other vertices in a line. Print 10^9 in case the vertex can't be reached form the source vertex.

*/

/*   CODE */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    String[] st = br.readLine().split(" ");
	    int n = Integer.parseInt(st[0]);
	    int m = Integer.parseInt(st[1]);
	    int[][] arr = new int[m][3];
	    for(int i=0;i<m;i++){
	        st = br.readLine().split(" ");
	        arr[i][0] = Integer.parseInt(st[0])-1;
	        arr[i][1] = Integer.parseInt(st[1])-1;
	        arr[i][2] = Integer.parseInt(st[2]);
	    }
	    int[] path = new int[n];
	    Arrays.fill(path,Integer.MAX_VALUE);
	    path[0] = 0;
	    
	    
	    
	    
	    for(int i =0 ;i<n-1;i++){
	        for(int j= 0;j<m;j++){
	            int u = arr[j][0];
	            int v = arr[j][1];
	            int wt = arr[j][2];
	            
	            if(path[u] == Integer.MAX_VALUE){
	                continue;
	            }
	            if(path[u] + wt < path[v]){
	                path[v] = path[u] + wt;
	            }
	        }
	    }
	    
	    for(int i=1;i<n;i++){
	        if(path[i] != Integer.MAX_VALUE){
	            System.out.print(path[i] +" ");
	        }else{
	            System.out.print("1000000000");
	        }
	    }
	    System.out.println();
        
			}
}

/*

SAMPLE INPUT:

5 5
1 2 5
1 3 2
3 4 1
1 4 6
3 5 5

*/

/*
SAMPLE OUTPUT:

5 2 3 7 

*/
