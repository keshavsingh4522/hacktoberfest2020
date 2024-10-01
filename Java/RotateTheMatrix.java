package matrix;

public class RotateTheMatrix {

	public static void main(String[] args) {
		// 8 : Rotate matrix by 90 degrees
		
		int[][] matrix = {{1, 2, 1, 4},
	             {3, 7, 8, 5},
	             {8, 7, 7, 3},
	             {8, 1, 2, 7},
	            };
		
		int temp=0;
        int n = matrix.length;
        
        for(int i=0; i<n/2; i++){
        	
            for(int j=i; j<n-i-1; j++){
            	
                temp = matrix[i][j];			// swaps the value
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
                
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
            	System.out.print(matrix[i][j] + " ");
            System.out.println();
        }
  }

}
