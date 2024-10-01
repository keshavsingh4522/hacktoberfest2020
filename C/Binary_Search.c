// C program to implement Recursive Binary Search 
#include <stdio.h> 
  
// A  recursive binary search function. It returns 
// location of x in given array arr[l..r] if present, 
// otherwise -1 
int binarySearch(int arr[], int l, int r, int x) 
{ 
  // base case
  if(l>h)return -1;
  //updating mid value each time with respect to l and r
  int mid=l+(r-l)/2;
  if(arr[mid]==x) //checking whether the mid value is the given x or not
    return mid;
  else if(arr[mid]<x)  // checking whether the selected mid value is less than the given x or not
    return binarySearch(a,mid+1,r,x);
  else
    return binarySearch(a,l,mid-1,x); 
 } 
  
int main(void) 
{ 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 10; 
  //Calling the binarySearch function
    int result = binarySearch(arr, 0, n - 1, x); 
    (result == -1) ? printf("Element is not present"
                            " in array") 
                   : printf("Element is present at "
                            "index %d", 
                            result); 
    return 0; 
} 
