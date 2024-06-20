package selfDsaPractice;

public class MergeShort {

	
	public static void main(String[] args) {
		
    	int arr [] = {3,0,4,1,7,12,2,5};
		int l = 0;
		int r = arr.length-1;
		
		                                     
		
		mergeShort(arr, l, r);
		
		for(int i:arr) {
			System.out.print(i + " ");
		}
	}
	static void mergeShort(int arr[],int l,int r) {
		
		int mid = (l+r)/2;
		if(l<r) {
			 
			 mergeShort(arr, l, mid);
			 mergeShort(arr, mid+1, r);
             mergeList(arr, l, mid, r);
	    }
		
		
	
	}
	
	static void mergeList(int arr[],int l,int m,int r) {
		
		
		//GFG solutiuon(Got it)
		
		    int n1 = m - l + 1;
	        int n2 = r - m;
	  
	        /* Create temp arrays */
	        int L[] = new int[n1];
	        int R[] = new int[n2];
	  
	        /*Copy data to temp arrays*/
	        for (int i = 0; i < n1; ++i)
	            L[i] = arr[l + i];
	        for (int j = 0; j < n2; ++j)
	            R[j] = arr[m + 1 + j];
	  
	        /* Merge the temp arrays */
	  
	        // Initial indexes of first and second subarrays                  
	        int i = 0, j = 0;
	  
	        // Initial index of merged subarray array
	        int k = l;
	        while (i < n1 && j < n2) {
	            if (L[i] <= R[j]) {
	                arr[k] = L[i];
	                i++;
	            }
	            else {
	                arr[k] = R[j];
	                j++;
	            }
	            k++;
	        }
	  
	        /* Copy remaining elements of L[] if any */
	        while (i < n1) {
	            arr[k] = L[i];
	            i++;
	            k++;
	        }
	  
	        /* Copy remaining elements of R[] if any */
	        while (j < n2) {
	            arr[k] = R[j];
	            j++;
	            k++;
	        }
	    }
		
		
	}

