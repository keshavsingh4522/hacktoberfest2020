//Sorting Array Using Selection Sort.
package com.java;

import java.util.Arrays;

public class Selection_Sort{
    public static void main(String[] args) {
        int[] arr = {1, 2, -4, -3, 44, 9, -23};
        Selection(arr); //sorting array elements using Selection sort
        System.out.println(Arrays.toString(arr));
    }

    //    Selection Sort
    static void Selection(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int last = arr.length - i -1;
            int max = Max(last, arr);
            swap(max, arr, last);
        }
    }

    //    Swapping of Max to Last
    static void swap(int max, int[] arr, int last) {
        if(arr[max] != arr[last]){
            int temp = arr[max];
            arr[max] = arr[last];
            arr[last] = temp;
        }
    }


    //    finding the Maximum Number Index
    static int Max(int last, int[] arr) {
        int max = 0;
        for(int  i = 0; i <= last; i++){
            if(arr[i] >= arr[max]){
                max = i;
            }
        }
        return max;
    }


}
