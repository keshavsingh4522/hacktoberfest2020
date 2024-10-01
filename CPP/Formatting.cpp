#include<bits/stdc++.h>
using namespace std;

int main(){
   int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
   int n = sizeof(arr) / sizeof(int);

   int first = -1, last = -1,x=2;
   for (int i = 0; i < n; i++) {
      if(arr[i]==x){
         if(first==-1){
            first=i;
         }else{
            last=i;
         }
      }
   }
   cout<<first<<endl;
   cout<<last<<endl;

}
