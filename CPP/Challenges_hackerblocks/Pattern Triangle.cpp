#include<iostream>

using namespace std;

int main()
{
     int n,i,j;
     cin>>n;

     for(i=1;i<=n;i++)
     {
          for(j=0;j<n-i;j++)
               cout<<"\t";
          for(j=i;j<2*i;j++)
               cout<<j<<"\t";
          for(j=2*i-2;j>=i;j--)
               cout<<j<<"\t";
          cout<<"\n";
     }
}
