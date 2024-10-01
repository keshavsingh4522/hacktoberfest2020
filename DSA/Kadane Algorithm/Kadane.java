import java.util.*;

class Kadane {

  int maxSubarraySum(int a[], int n) {
    int max = a[0];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (sum > max)
        max = sum;
      if (sum < 0)
        sum = 0;
    }
    return max;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = sc.nextInt();
    }
    int ans = MaxSubArray(arr, n);
  }
}