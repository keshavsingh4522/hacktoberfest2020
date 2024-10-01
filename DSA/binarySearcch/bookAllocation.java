package Algo.binarySearcch;

public class bookAllocation {

	public static int maxValue( int[]  n ) {
		int max = Integer.MIN_VALUE;
		for(int each: n)
		if(each > max)
		max = each;
		 
		return max;
		}
	
//	static int minPages(int a[] , int h) {
//		int min = maxValue(a);
//	}
	
	
	public static void main(String[] args) {
		int[] arr = {2,4,6,8,20};
	    System.out.println(maxValue(arr));

	}

}
