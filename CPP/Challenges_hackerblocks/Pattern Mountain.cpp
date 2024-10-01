#include<iostream>

using namespace std;

int main()
{
     int n,i,j,k;
     cin>>n;

     k=(2*n)-3;

     for(i=1;i<=n;i++)
     {
          for(j=1;j<=i;j++)
               cout<<j<<"\t";
          for(j=1;j<=k;j++)
               cout<<"\t";
          if(i==n)
          {
               for(j=i-1;j>=1;j--)
               cout<<j<<"\t";
          }
          else
          {
               for(j=i;j>=1;j--)
               cout<<j<<"\t";
          }
          k-=2;
          cout<<"\n";
     }
}
