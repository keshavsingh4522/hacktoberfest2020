#include<bits/stdc++.h>
using namespace std;
int main(){
   int a[]={5,4,1,4,3,5,1};
   int res=0;
   for (int i = 0; i < 7; i++)
   {
      res^=res^a[i];
   }
   cout<<res<<endl;
}
