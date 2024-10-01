import java.util.*;
public class BinarySearch { 

    public static int binarySearch(int[] arr, int key) {
    	//Your code goes here
        int start = 0;
        int end  = arr.length-1;
        
        while(start <= end){
            int mid = start+(end-start)/2;
            if(arr[mid] == key){
                return mid;
            }else if(arr[mid] > key){
                end = (mid-1);
            }else {
                start = (mid+1);
            }
        }
        return -1;
    }
}
