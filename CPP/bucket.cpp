
import java.util.*;
import java.util.Collections;

class bucket {


	static void bucketSort(float arr[], int n)
	{
		if (n <= 0)
			return;

		
		@SuppressWarnings("unchecked")
		Vector<Float>[] buckets = new Vector[n];

		for (int i = 0; i < n; i++) {
			buckets[i] = new Vector<Float>();
		}

	
		for (int i = 0; i < n; i++) {
			float idx = arr[i] * n;
			buckets[(int)idx].add(arr[i]);
		}

	//elliot37
		for (int i = 0; i < n; i++) {
			Collections.sort(buckets[i]);
		}

		// 4) Concatenate all buckets into arr[]
		int index = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < buckets[i].size(); j++) {
				arr[index++] = buckets[i].get(j);
			}
		}
	}

	
	public static void main(String args[])
	{
		float arr[] = { (float)0.897, (float)0.565,
						(float)0.656, (float)0.1234,
						(float)0.665, (float)0.3434 };

		int n = arr.length;
		bucketSort(arr, n);

		System.out.println("Sorted array is ");
		for (float el : arr) {
			System.out.print(el + " ");
		}
	}
}

// This code is contributed by elliot37
