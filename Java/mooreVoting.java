import java.util.*;
public class MyClass {
    public static void main(String args[]) {
      Scanner sc = new Scanner(System.in);
      System.out.print("enter number of elements in array : ");
      int n = sc.nextInt();
      System.out.println();
      int[] nums = new int[n];
      System.out.println("enter array elemnts : ");
      for(int i=0 ; i<n ;i++){
          nums[i] = sc.nextInt();

      }
      System.out.println("maority element is " + majorityElement(nums));
    }
    public static int majorityElement(int[] nums) {
        int count = 1;
        int ele = nums[0];
        for(int i=1 ; i<nums.length ; i++){
            if(count == 0){
                count = 1;
                ele = nums[i];
            }else if(nums[i] == ele)
                count++; 
            else{
                count -- ;
            }
        }
        return ele;
    }
}
