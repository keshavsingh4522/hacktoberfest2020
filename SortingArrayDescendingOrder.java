
import java.util.Scanner;

public class SortingArrayDescendingOrder {

	public static void main(String[] args) {
		int[] x;
		x = new int[10];
		int temp;

		Scanner scan = new Scanner(System.in);
		for (int i = 0; i < 10; i++) {
			System.out.print("Enter value : ");
			x[i] = scan.nextInt();
		}
		scan.close();// to close scanner

		for (int i = 0; i < 10; i++) {
			for (int j = i + 1; j < 10; j++) {
				if (x[i] < x[j]) {
					temp = x[i];
					x[i] = x[j];
					x[j] = temp;
				}
			}

		}
		System.out.print("\nArray elements after sorting:\n");
		for (int i = 0; i < 10; i++) {
			System.out.print(x[i] + " ");
		}

	}

}
