
import java.util.*;

public class QuickSort {

	public static void main(String[] args) {
		int[] arr = { 5, 3, 4, 1, 2 };
		quickSort(arr,0,arr.length-1);
		System.out.println(Arrays.toString(arr));

	}

	static void quickSort(int[] arr, int low, int high) {
		if (low < high) {
            
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
	}

    static int partition(int[] arr, int low, int high) {
        

        int pivot = arr[high];
 
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        
        
        swap(arr, i + 1, high);  
        return i + 1;
    }

	static void swap(int[] arr, int first, int second) {
		int temp = arr[first];
		arr[first] = arr[second];
		arr[second] = temp;
	}

}
