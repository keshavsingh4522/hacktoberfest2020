package com.Questions;

public class SearchRotatedArray {
    public static void main(String[] args) {
        int[] arr = {10, 11, 12};

        System.out.println(search(arr, 12));
    }

    public static int peakIndexInMountainArray(int[] arr) {
        int low = 0, high = arr.length-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(arr[(mid)] > arr[(mid+1)%arr.length]){
                return mid;
            }else if(arr[mid] >= arr[0]){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }

        return -1;
    }

    public static int BS(int[] arr, int low, int high, int target, boolean reverse){
        while(low <= high){
            int mid = low + (high - low)/2;

            if(arr[(mid)] == target){
                return mid;
            }else if(arr[(mid)] > target){
                if(reverse)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else{
                if(!reverse)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }

    public static int search(int[] nums, int target) {
        int peak = peakIndexInMountainArray(nums);

        int left = BS(nums, 0, peak, target, false);
        if(left != -1) return left;

        int right = BS(nums, peak+1, nums.length-1, target, false);

        return right;
    }
}
