#include<bits/stdc++.h>
using namespace std;
void reverseArray(int *arr,int n){
  //function of reverse array

   int s=0;
   int e=n-1;

   while (s<=e)
   {
      swap(arr[s],arr[e]);
      s++;e--;
   }

}
int main(){

   int arr[]={1,2,3,4,5,6};
   int n=6;
   reverseArray(arr,n);
   for (int i = 0; i < n; i++)
   {
      cout<<arr[i]<<" ";
   }
}
