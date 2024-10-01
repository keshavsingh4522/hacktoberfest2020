package Algo.binarySearcch;
import java.util.*;
public class elementInSortedAndRotated {

	static int bSearch(int a[], int key) {
		int low=0 , high =a.length-1;
		while(low<= high) {
			int mid = (low+high)/2;
			if(a[mid]==key) return mid;
			if(a[low] <= a[mid]) {
			if(key >= a[low] && key <a[mid]) {
				high = mid-1;
			}else {
				low = mid+1;
			}
		   }else {
			   if (key > a[mid] && key<= a[high]) {
				   low = mid+1;
			   }else {
				   high = mid-1;
			   }
		   }
		}
		return -1;
	} 
	
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int a[] = {20, 30, 40, 50, 60, 5, 10};
            
//            int n =  a.length;
//            
//            int key = 10;
            
            System.out.println(bSearch(a, 40));

	}

}
