import java.util.Scanner; 
class Solution {
    public int[] runningSum(int[] nums) {
        int arr []=new int[nums.length];
        for(int i=0;i<nums.length;i++){
            for(int j=0;j<=i;j++){
            arr[i]=arr[i]+nums[j];
        }
        }
        return arr;    
    }
}
