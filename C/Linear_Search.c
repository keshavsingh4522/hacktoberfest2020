#include<stdio.h>
 int Search(int arr[], int n, int key)
 {
   for(int i=0; i<=n; i++){
 if (arr[i]==key){
return i;
 }
     return -1;
   }
   int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    int result = search(arr, N, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}
