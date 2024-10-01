import java.util.*;
public class BinarySearchUsingRecursion {
	public static void main(String[] args) {
// 		int[] arr = {1,2,34,5,12,98,213};
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the key");
		int key = sc.nextInt();
    System.out.println("Enter the length For array");
    int n = sc.nextInt();
    int arr[] = new int[n];
    for(int i=0;i<n;i++){
      arr[i] = sc.nextInt();
    }
		int start = 0;
		int end = arr.length;
		int v = search(arr, start, end, key);
		if(v==1) {
			System.out.println("Key is found");
		}
		else {
			System.out.println("Key is not found");
		}
	}
	static int search(int[] a,int start, int end,int key) {
		int mid = (start + end)/2;
		if(a[mid]==key) {
			return 1;
		}
		if(a[mid] > key) {
			return search(a, start, mid-1, key); 
		}
		else {
			return search(a, mid+1, end, key);
		}
	
	}
}
