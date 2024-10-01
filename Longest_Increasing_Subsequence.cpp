/* ALGORITHM :
Begin
   define array length of size n
   initially set 0 to all entries of length

   for i := 1 to n-1, do
      for j := 0 to i-1, do
         if subarray[j] < subarray[i] and length[j] > length[i], then length[i] := length[j]
      done

      increase length[i] by 1
   done

   lis := 0
   for i := 0 to n-1, do
      lis := maximum of lis and length[i]
   done

   return lis
End
*/

//Program :

#include <iostream>
using namespace std;

int longestSubSeq(int subArr[], int n) {
   int length[n] = { 0 };                    //set all length to 0
   length[0] = 1;                            //subsequence ending with subArr[0] is 1

   for (int i = 1; i < n; i++) {            //ignore first character, second to all
      for (int j = 0; j < i; j++) {         //subsequence ends with subArr[j]
         if (subArr[j] < subArr[i] && length[j] > length[i])
            length[i] = length[j];
      }
      length[i]++;              //add arr[i]
   }
   int lis = 0;
   for (int i = 0; i<n; i++)           // find longest increasing subsequence
      lis = max(lis, length[i]);
   return lis;
}
int main() {
   int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
   int n = 16;
   cout<<"Length of Longest Increasing Subsequence is: " << longestSubSeq(arr, n);
   return 0;
}