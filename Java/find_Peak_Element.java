// 162 - Leetcode - https://leetcode.com/problems/find-peak-element/

public class find_Peak_Element {
    public static void main(String[] args) {
        int[] nums = { 1, 2, 1, 3, 5, 6, 4 };
        int peakIndex = findPeakElement(nums);
        System.out.println(peakIndex);
    }

    private static int findPeakElement(int[] nums) {
        int low = 0, high = nums.length - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int mid2 = mid + 1;
            if (nums[mid] < nums[mid2])
                low = mid2;
            else
                high = mid;
        }
        return low;
    }
}
