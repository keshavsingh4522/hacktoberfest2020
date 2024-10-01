package matrix;

import java.util.ArrayList;

public class SpiralTraverse {

	public static void main(String[] args) {
		// 1 : Spiral traversal on a Matrix
		
		int[][] matrix = {{1, 2, 3, 4},
				          {5, 6, 7, 8},
				          {9, 10, 11, 12}};
        int m = matrix.length, n = matrix[0].length;
        
        int i = 0;
        int k = 0, l = 0;

        ArrayList<Integer> a = new ArrayList<Integer>();

        while(k < m && l < n)
        {
            for(i = l; i < n; i++)
                a.add(matrix[k][i]);
            k++;
            for(i = k; i < m; i++)
                a.add(matrix[i][n-1]);
            n--;

            if(k < m)
            {
                for(i = n - 1; i >= l; i--)
                    a.add(matrix[m-1][i]);
                m--;
            }
            if(l < n)
            {
                for(i = m - 1; i >= k; i--)
                    a.add(matrix[i][l]);
                l++;
            }
        }
		
		System.out.println(a);
		
	}

}
