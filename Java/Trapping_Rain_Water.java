package array;
public class Trapping_Rain_Water {
	public static void main(String[] args) {
		int arr[] = {3, 0, 1, 2, 5}, i=0, n =arr.length;
		System.out.println("Array : ");
		for (i = 0; i < arr.length; i++) 
			System.out.print(arr[i]+" ");
		int res = trap(arr, i, n);
		System.out.println("\nRain Water Trapped "+res);		
	}
	static int trap(int arr[], int st, int n) {
		if(check_if_Sorted.isSorted(arr, st, n))	return 0;
		if (check_if_Sorted.isSorted(reverseArray.reverse2(arr,st,n), st, n))	return 0;
		if(arr.length<3) return 0;
		int LL = LargestElement.largestIndex(arr,st,n/2), LR = LargestElement.largestIndex(arr,n/2,n);
		int Sin =0; //Second Largest Element Index
		int dis = LR-LL-1;	// Distance b/2 Largest from Left with Right
		if(dis<1) return 0; 
		if(arr[LL]>arr[LR])	Sin = LR;	else Sin = LL;
		int space = dis*arr[Sin],occupied=0;
		for (int i = LL+1; i < LR; i++) {
			occupied += arr[i];
		}
		return space-occupied ;
	}
}
