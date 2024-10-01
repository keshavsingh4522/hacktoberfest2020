#include<bits/stdc++.h>
using namespace std;
// bool IsPerfect(int a[],int n)
//     {
//         int temp[n];
//         bool ans=true;
//         for(int i=n-1;i>0;i--){
//             temp[i]=a[i];
//         }
//         for(int i=0;i<n;i++){
//             if(temp[i]!=a[i]){
//                 ans=false;
//                 break;
//             }else{
//                ans=true;
//             }
//         }
//         return ans;
// }
int main(){
   int n=5;
   int arr[n]={1,2,3,2,1};

   int s=0,e=n-1;
   bool flag=true;
   while (s<=e)
   {
    if(arr[s]!=arr[e]){
      flag=false;
      break;
    }
    s++;
    e--;
   }

   cout<<flag<<endl;

}
