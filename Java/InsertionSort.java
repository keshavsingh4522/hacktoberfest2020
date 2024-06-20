import java.util.Arrays;
public class insertionSort {
	public static void sort(int []arr) {
		int num = arr.length;
		for(int i =1;i<num;i++)
		{
			int k = arr[i];
			int j = i-1;
			while(j>=0 && arr[j]>=k)
			{
				arr[j+1]=arr[j];
				j=j-1;
			}
		arr[j+1] = k;
		}
	}
   public static void main(String[] args) {
		int arr[]= {4,5,3,2,1,55,4,8,7,4,1};
		System.out.println("before sorting array as following :");
		System.out.println(Arrays.toString(arr));
		
		sort(arr);
		System.out.println("After sort looks as follows:");
		for(int i : arr)
		{
	   System.out.print(i+" ");
		}

   }}
