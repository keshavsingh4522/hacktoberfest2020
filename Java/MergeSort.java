public class MergeSort
{
	void merge(int arr[], int low, int mid, int up)
	{
		int n1 = mid - low + 1;
		int n2 = up - mid;

		int Left[] = new int[n1];
		int Right[] = new int[n2];

		for (int i = 0; i < n1; ++i)
			Left[i] = arr[low + i];
		for (int j = 0; j < n2; ++j)
			Right[j] = arr[mid + 1 + j];

		int i = 0, j = 0;

		int k = low;
		while (i < n1 && j < n2) {
			if (Left[i] <= Right[j]) {
				arr[k] = Left[i];
				i++;
			}
			else {
				arr[k] = Right[j];
				j++;
			}
			k++;
		}
		while (i < n1) {
			arr[k] = Left[i];
			i++;
			k++;
		}
		while (j < n2) {
			arr[k] = Right[j];
			j++;
			k++;
		}
	}


	void sort(int arr[], int low, int up)
	{
		if (low < up) {
			int mid =low + (up-low)/2;
			sort(arr, low, mid);
			sort(arr, mid + 1, up);
			merge(arr, low, mid, up);
		}
	}


	static void printArray(int arr[])
	{
		int n = arr.length;
		for (int i = 0; i < n; ++i)
			System.out.print(arr[i] + " ");
	}


	public static void main(String args[])
	{
		int arr[] = {29, 7, 5, 9, 50, 8, 17, 1, 6, 11};

		MergeSort ob = new MergeSort();
		ob.sort(arr, 0, arr.length - 1);

		System.out.println("Sorted array");
		printArray(arr);
	}
}
