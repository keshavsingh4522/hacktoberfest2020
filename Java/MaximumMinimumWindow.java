package DataStructures.Stacks;

import java.util.Arrays;
import java.util.Stack;

public class MaximumMinimumWindow {

    public static int[] calculateMaxOfMin(int[] arr, int n) {
        Stack<Integer> s = new Stack<>();
        int left[] = new int[n + 1];
        int right[] = new int[n + 1];
        for (int i = 0; i < n; i++) {
            left[i] = -1;
            right[i] = n;
        }

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.peek()] >= arr[i])
                s.pop();

            if (!s.empty())
                left[i] = s.peek();

            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.peek()] >= arr[i])
                s.pop();

            if (!s.empty())
                right[i] = s.peek();

            s.push(i);
        }

        int ans[] = new int[n + 1];
        for (int i = 0; i <= n; i++)
            ans[i] = 0;

        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;

            ans[len] = Math.max(ans[len], arr[i]);
        }

        for (int i = n - 1; i >= 1; i--)
            ans[i] = Math.max(ans[i], ans[i + 1]);

        // Print the result
        for (int i = 1; i <= n; i++)
            System.out.print(ans[i] + " ");
        return ans;
    }

    public static void main(String args[]) {
        int[] arr = new int[]{10, 20, 30, 50, 10, 70, 30};
        int[] target = new int[]{70, 30, 20, 10, 10, 10, 10};
        int[] res = calculateMaxOfMin(arr, arr.length);
        assert Arrays.equals(target, res);
    }

}
