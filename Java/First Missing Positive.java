// Given an unsorted integer array arr, return the smallest missing positive integer.
import java.util.Arrays;
public class Main {
    public static void main(String[] args) {
        int[] arr=new int[]{1,2,0};
        System.out.println(firstMissingPositive(arr));
    }
    public static int firstMissingPositive(int[] nums) {
        int i=0;
        while(i<nums.length){
            int correct=nums[i]-1;
            if(nums[i] > 0 && nums[i]<nums.length && nums[i]!=nums[correct]){
                swap(nums,i,correct);
            }else{
                i++;
            }
        }
        for(int j=0;j<nums.length;j++){
            if(nums[j]!=j+1){
                return j+1;
            }
        }
        return nums.length+1;
    }
    static void swap(int[] arr,int i,int correct) {
        int temp=arr[i];
        arr[i]=arr[correct];
        arr[correct]=temp;
    }
}