package Algo.binarySearcch;

public class elementInfiniteArray {
	
	static int binaryS(int a[] , int key , int low , int high) {
		if(low > high) return -1;
		int mid = (low+high)/2;
		if(a[mid]==key) {
			return mid;
		}
		if(key> a[mid]) return binaryS(a , key , mid+1 , high);
		return binaryS(a , key , low, high-1);
	} 
	
	static int searchI(int a[] , int key) {
    	  int low = 0;
    	  int high = 1;
    	  
    	  while(a[high]<key){
    		  low= high;
    		  high =2*high;
    	  }
    	  return binaryS(a , key , low, high);
      }
	
	public static void main(String[] args) {
		int a[] = {1 ,3,7,8,12,58,72,82,96};
	}

}
