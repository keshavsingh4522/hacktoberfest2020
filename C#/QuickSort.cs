using System;
					
public class Program
{
	public static void Main()
	{
		int[] arr = new int[] { -1, -5, 2, 10, 0, 4, 9 };
		foreach (int a in arr) Console.Write(a + " ");
		Console.WriteLine();
		
		QuickSort quick = new QuickSort();
		quick.Sort(arr, 0, 6);
		foreach (int a in arr) Console.Write(a + " ");
	}
}

public class QuickSort
{
	public int Partition(int[] arr, int left, int right)
	{
		int pivot; int temp;
		pivot = arr[left];
		while (true)
		{
			while (arr[left] < pivot)
			{
				left++;
			}
			while (arr[right] > pivot)
			{
				right--;
			}
			if (left < right)
			{
				temp = arr[right];
				arr[right] = arr[left];
				arr[left] = temp;
			}
			else
			{
				return right;	
			}
		}
	}
	
	public void Sort(int[] arr, int left, int right)
	{
		int pivot;
		if (left < right)
		{
			pivot = Partition(arr, left, right);
			if (pivot > 1)
			{
				Sort(arr, left, pivot - 1);
			}
			if (pivot + 1 < right)
			{
				Sort(arr, pivot + 1, right);
			}
		}
	}
}
