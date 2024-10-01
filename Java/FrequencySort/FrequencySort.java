/* This is a JAVA program to sort an array in increasing order based on the frequency of the values. 
If multiple values have the same frequency, sort them in decreasing order */

/* input : number of elements :6
           array : [1, 1, 2, 2, 2, 3]
   output :
           array : [3, 1, 1, 2, 2, 2]
*/
import java.io.*;
import java.util.*;
import java.lang.*;

/* Name of the class has to be "Main" only if the class is public. */
public class FrequencySort {

    public static void frequencySort(int nums[]) {
        // init hashmap and count occurences of elements in nums
        // init minHeap based on occurence, if two elements have same freq sort in
        // decreasing order
        // add elements in map into minHeap as array, containing element and occurence
        // init index to traverse array
        // loop while minHeap is not empty
        // grab min element
        // keep inserting element into nums while in bounds and occurence > 0
        // return nums

        Map<Integer, Integer> map = new HashMap<>();

        for (int i : nums) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }

        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[1] == b[1] ? b[0] - a[0] : a[1] - b[1]);

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            minHeap.add(new int[] { entry.getKey(), entry.getValue() });
        }

        int index = 0;

        while (!minHeap.isEmpty()) {
            int min[] = minHeap.poll();

            while (index < nums.length && min[1] > 0) {
                nums[index++] = min[0];
                min[1]--;
            }
        }
        // System.out.println("Final resultant array");
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in); // creating scanner for total elements to be inserted in array
        // System.out.println("enter total count of elements -> ");
        int n = input.nextInt(); // user will enter total elements
        int array[] = new int[n];

        for (int i = 0; i < n; i++) {
            array[i] = input.nextInt();
            // decrement till the index became 0
        }
        input.close();
        frequencySort(array);

    }
}