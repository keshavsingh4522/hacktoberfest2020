#include<bits/stdc++.h>
using namespace std;
int main(){

   int t;
   cin>>t;
   while (t--)
   {
      int a,b;
      cin>>a>>b;
      if(a==b){
         cout<<"Yes"<<endl;
      }else if(abs(a-b)%2==0){
         cout<<"Yes"<<endl;
      }
      else{
         cout<<"No"<<endl;
      }
   }
   

}
