
/*    
PROBLEM STATEMENT:

1. You are given an array(arr) of integers.
2. You have to sort the given array in increasing order using the merge sort.
*/

/*
CONSTRAINTS:

1 <= N <= 100000
-10^9 <= arr[i] <= 10^9

*/

/*
INPUT FORMAT:

An Integer n 
arr1
arr2..
n integers

*/




/*   CODE */
import java.io.*;
import java.util.*;

public class Main {

  public static int[] mergeSort(int[] arr, int lo, int hi) {
    if(lo == hi){
        int[] base = new int[1];
        base[0] = arr[lo];
        return base;
    }
   int mid = (lo + hi)/2;
   int[] fsh = mergeSort(arr,lo,mid);
   int[] ssh = mergeSort(arr,mid+1,hi);
   int[] ms = mergeTwoSortedArrays(fsh,ssh);
    return ms;
  }

  //used for merging two sorted arrays
  public static int[] mergeTwoSortedArrays(int[] a, int[] b){
    System.out.println("Merging these two arrays ");
    System.out.print("left array -> ");
    print(a);
    System.out.print("right array -> ");
    print(b);
    int i = 0, j =0, k = 0;
    int[] ans = new int[a.length + b.length];
    while(i < a.length && j < b.length){
        if(a[i] <= b[j]){
          ans[k] = a[i];
          i++;
          k++;
        }else{
          ans[k] = b[j];
          j++;
          k++;
        }
    }

    while(i < a.length){
      ans[k] = a[i];
      k++;
      i++;
    }

    while(j < b.length){
      ans[k] = b[j];
      k++;
      j++;
    }
    
    return ans;
  }

  public static void print(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
      System.out.print(arr[i] + " ");
    }
    System.out.println();
  }

  public static void main(String[] args) throws Exception {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = scn.nextInt();
    }
    int[] sa = mergeSort(arr,0,arr.length - 1);
    System.out.print("Sorted Array -> ");
    print(sa);
  }

}




/*
SAMPLE INPUT:
5
7 
-2 
4 
1 
3
*/

/*
SAMPLE OUTPUT:

Merging these two arrays 
left array -> 7 
right array -> -2 
Merging these two arrays 
left array -> -2 7 
right array -> 4 
Merging these two arrays 
left array -> 1 
right array -> 3 
Merging these two arrays 
left array -> -2 4 7 
right array -> 1 3 
Sorted Array -> -2 1 3 4 7 

*/
