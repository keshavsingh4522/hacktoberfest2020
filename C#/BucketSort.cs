// C# program to sort an array
// using bucket sort
using System;
using System.Collections;
using System.Collections.Generic;
class GFG {
 
  // Function to sort arr[] of size n
  // using bucket sort
  static void bucketSort(float []arr, int n)
  {
    if (n <= 0)
      return;
 
    // 1) Create n empty buckets
    List<float>[] buckets = new List<float>[n];
 
    for (int i = 0; i < n; i++) {
      buckets[i] = new List<float>();
    }
 
    // 2) Put array elements in different buckets
    for (int i = 0; i < n; i++) {
      float idx = arr[i] * n;
      buckets[(int)idx].Add(arr[i]);
    }
 
    // 3) Sort individual buckets
    for (int i = 0; i < n; i++) {
      buckets[i].Sort();
    }
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < buckets[i].Count; j++) {
        arr[index++] = buckets[i][j];
      }
    }
  }
 
  // Driver code
  public static void Main()
  {
    float []arr = { (float)0.897, (float)0.565,
                   (float)0.656, (float)0.1234,
                   (float)0.665, (float)0.3434 };
 
    int n = arr.Length;
    bucketSort(arr, n);
 
    Console.WriteLine("Sorted array is ");
    foreach(float el in arr) {
      Console.Write(el + " ");
    }
  }
}
