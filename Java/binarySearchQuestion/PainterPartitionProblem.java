import java.util.*;

public class PainterPartitionProblem {

	public static void main(String[] args) {
		// BINARY SEARCH
		Scanner scn = new Scanner(System.in);
		// TAKING INPUT FOR THE LENGTH OF THE ARRAY
		System.out.println("Enter the Length of the Array ");
		int n = scn.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = scn.nextInt();
		}
		// TAKING INPUT FOR NUMBER OF PAINTERS
		System.out.println("Enter number of painters");
		int k = scn.nextInt();

		int ans = minimumtime(a, k);
		System.out.println("The minimum time taken to paint all the block ");
		System.out.println(ans);
	}

	private static int getSum(int[] a) {
		int sum = 0;
		for (int i = 0; i < a.length; i++) {
			sum = sum + a[i];
		}
		return sum;
	}

	private static int getMax(int[] a) {
		int max = Integer.MIN_VALUE;
		for (int i = 0; i < a.length; i++) {
			if (max < a[i])
				max = a[i];
		}
		return max;
	}

	private static int minimumtime(int[] a, int k) {
		int hi = getSum(a);
		int lo = getMax(a);
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			int numberofpainters = required_number_of_painter(a, k, mid);
			if (numberofpainters <= k)
				hi = hi - 1;
			else if (numberofpainters > mid) {
				lo = lo + 1;
			}
		}
		return lo;
	}

	private static int required_number_of_painter(int[] a, int k, int mid) {
		int total = 0;
		int num = 1;
		for (int i = 0; i < a.length; i++) {
			total = total + a[i];
			if (total > mid) {
				total = a[i];
				num++;
			}
		}
		return num;
	}

}
