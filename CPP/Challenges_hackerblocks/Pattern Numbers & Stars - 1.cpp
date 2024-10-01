#include<iostream>

using namespace std;

int main()
{
     int n;
     cin>>n;

     int i,j;

     for(i=0;i<n;i++)
     {
          for(j=1;j<=n-i;j++)
               cout<<j<<" ";
          for(j=0;j<2*i-1;j++)
               cout<<"* ";
          cout<<"\n";
     }
}
