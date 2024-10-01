package com.company;

import java.util.Arrays;

//Time complexity is N^2

public class Selection_sort {
    public static void main(String[] args) {
        int[] arr = {5,3,1,2,4};
        select(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void select(int[] arr){
        for (int i = 0; i < arr.length; i++) {
            //find the max item in the remaining array and swap it with correct index

            int last = arr.length-i-1; //last is the index
            int maxIndex = getMaxIndex(arr,0,last);
            swap(arr,maxIndex,last);
        }
    }
    static int getMaxIndex(int[] arr, int start, int end){
        int max = start; //max is the index
        for (int i = start ; i <= end; i++) {
            if(arr[max] <arr[i]){
                max = i;
            }
        }
        return max;
    }
    static void swap(int[] arr, int maxIndex, int end){
        int temp = arr[maxIndex];
        arr[maxIndex] = arr[end];
        arr[end] = temp;
    }


}

