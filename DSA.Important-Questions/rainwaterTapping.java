public class Rainwatertrapping {
    // DO NOT MODIFY THE ARGUMENTS WITH "final" PREFIX. IT IS READ ONLY
    public int trap(final int[] A) {
        int i;
        int n = A.length;
        if (n == 1)
            return 0;
        int leftMax[] = new int[n];
        int rightMax[] = new int[n];

        leftMax[0] = 0;
        leftMax[n - 1] = 0;
        rightMax[n - 1] = 0;

        for (i = 1; i < n - 1; i++)
            leftMax[i] = Math.max(leftMax[i - 1], A[i - 1]);
        for (i = n - 2; i > 0; i--)
            rightMax[i] = Math.max(A[i + 1], rightMax[i + 1]);

        int ans = 0;
        for (i = 1; i < n - 1; i++) {
            int x = Math.min(leftMax[i], rightMax[i]);
            if (x - A[i] > 0)
                ans += x - A[i];

        }
        return ans;

    }
}
