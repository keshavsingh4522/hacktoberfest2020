package graph;

public class PetersonGraph {
	
	static char []S = new char[100005];
	 
    static boolean [][]adj = new boolean[10][10];
     
    static char[] result = new char[100005];
    
    static boolean findPath(char S[],int v) {
    	result[0]=(char)(v+'0');
    	for(int i=1;i<(int)S.length;i++) {
    		if(adj[v][S[i]-'A'] || adj[S[i]-'A'][v]) {
    			v=S[i]-'A';
    		}else if(adj[v][S[i]-'A'+ 5] || adj[S[i]-'A'+ 5][v]) {
    			v = S[i]-'A'+5; 
    		}else {
    			return false;
    		}
    		result[i] = (char)(v+'0');
    	}
    	return true;
    }

	public static void main(String[] args) {
		adj[0][1] = adj[1][2] = adj[2][3] = adj[3][4] =
		        adj[4][0] = adj[0][5] = adj[1][6] = adj[2][7] =
		        adj[3][8] = adj[4][9] = adj[5][7] = adj[7][9] =
		        adj[9][6] = adj[6][8] = adj[8][5] = true;
		         
		        // path to be checked
		        char S[] = "ABB".toCharArray();
		         
		        if (findPath(S, S[0] - 'A') || findPath(S, S[0] - 'A' + 5))
		        {
		            System.out.print(result);
		        }
		        else
		        {
		            System.out.print("-1");
		        }
	}

}
