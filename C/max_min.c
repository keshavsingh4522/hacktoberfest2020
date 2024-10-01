#include <limits.h>
#include <stdio.h>
  
// Recursive function to find the minimum
// and the maximum element of the array
void recursiveMinMax(int arr[], int N,
                     int* minE, int* maxE)
{
    // Base Case
    if (N < 0) {
        return;
    }
  
    // If current element is smaller
    // than minE then update it
    if (arr[N] < *minE) {
        *minE = arr[N];
    }
  
    // If current element is greater
    // than maxE then update it
    if (arr[N] > *maxE) {
        *maxE = arr[N];
    }
  
    // Recursive call for next iteration
    recursiveMinMax(arr, N - 1, minE, maxE);
}
  
// Function to find the minimum and
// maximum element of the array
void findMinimumMaximum(int arr[], int N)
{
    int i;
  
    // variable to store the minimum
    // and maximum element
    int minE = INT_MAX, maxE = INT_MIN;
  
    // Recursive Function to find
    // minimum & maximum element
    recursiveMinMax(arr, N - 1, &minE, &maxE);
  
    // Print the minimum and maximum element
    printf("The minimum element is %d", minE);
    printf("\n");
    printf("The maximum element is %d", maxE);
  
    return;
}
  
// Driver Code
int main()
{
  
    int n;
	printf("Enter size of array");
	scanf("%d",&n);
    int arr[n];
  
    
    findMinimumMaximum(arr, n);
    return 0;
}
