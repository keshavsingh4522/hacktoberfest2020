package selfDsaPractice;

public class QuickShort {

	public static void main(String[] args) {
		
		
		int arr[] = {11,5,3,8,1,6,9};
		quickShort(arr, 0, arr.length-1);
		
		for(int i = 0; i<arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		
	}
	
	
	
	static int partion(int [] arr,int l,int h) {
		
		int pivot = arr[l];
		int i = l;
		int j = h;
		while(i<j) {
			
			while(arr[i]<=pivot) {
				
				i++;
				if(i == arr.length-1) {
					break;
				}
				
			}
			while(arr[j]>pivot) {
				
				j--;
				if(j == l) {
					break;
				}
			}
			
			if(i<j) {
				
				swap(arr, i, j);
			}
			
		}
		
		swap(arr, j, l);
	    return j;
		
	}
	
	static void quickShort(int arr[],int l,int h) {
		
		if(l<h) {
			
			int pivot = partion(arr, l, h);
			quickShort(arr, l, pivot-1);
			quickShort(arr, pivot+1, h);
			
		}
		
	}
	
	static void swap(int arr[],int i, int j) {
		
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		
	}

}
