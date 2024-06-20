import java.util.Scanner;

public class movenegativenumbersToside {
    public static void print(int a[], int n) {
        for (int i = 0; i < n; i++)
            System.out.print(a[i] + " ");
    }

    public static void rearrange(int a[], int n) {
        int temp, j = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                if (i != j) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
                j++;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        rearrange(a, n);
        print(a, n);
    }
}
