import Java.util.*;  
import java.util.Scanner;

public class NumberOfIslands {
	static int[] x = {-1,0,0,1};
	static int[] y = {0,1,-1,0};
	public static int numIslands(char[][] array) {
		if(array==null || array.length==0) return 0;
		int islands = 0;
		for(int i=0;i<array.length;i++) {
			for(int j=0;j<array[i].length;j++) {
				if(array[i][j]=='1') {
					islands(array,i,j);
					islands++;
				}
			}
		}
		return islands;
	}
	public static void islands(char[][] array, int i, int j) {
		array[i][j]='x';
		for(int d=0;d<x.length;d++) {
			if(i+y[d]<array.length && i+y[d]>=0 && j+x[d]<array[0].length && j+x[d]>=0 && array[i+y[d]][j+x[d]]=='1') {
				islands(array,i+y[d],j+x[d]);
			}
		}
	}
}