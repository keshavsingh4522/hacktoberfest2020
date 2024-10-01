package com.company;

public class LinearSearch {
    /*public static void main(String[] args) {
        int[] nums ={23, 45, 1, 2, 8, 19, -3, 16, -11, 28};
        int target = 19;
        int ans = linearSearch(nums,target);
        System.out.println(ans);
    }
     */

    //search in the array : return the index of the item found
    //otherwise if item not found return -1

    static int linearSearch(int arr[], int target){
        if(arr.length ==0){
            return -1;
        }

        // run a for loop
        for(int index =0; index< arr.length; index++){
            //check for element at every index if it is equal to target
            int element  = arr[index];
            if(element == target){
                return index;
            }
        }
         // This line will execute if none of the return statements above have executed
        //Hence the target not found
        return -1;
    }

    // Even digits problem-
    public static void main(String[] args) {
        int[] nums = {12,345,2,6,7896};
        System.out.println(findNumbers(nums));
        System.out.println(digits(5678));
    }

    static int findNumbers(int[] nums){
        int count =0;
        for(int num:nums){
            if(even(num)){
                count++;
            }
        }
        return count;
    }

    // function to check whether a number contains even digits or not
    static boolean even(int num){
        int numberOfDigits = digits(num);
        /*
        if(numberOfDigits % 2==0){
          return true;
        )
        return false;
         */
        return numberOfDigits% 2==0;
    }

    // count number of digits( int num)
    static int digits(int num){
        int count = 0;
        if(num <0){
            num = num*-1;
        }
        if(num ==0){
            return 1;
        }
        while(num>0){
            count++;
            num /= 10;
        }
        return count;
    }
}
