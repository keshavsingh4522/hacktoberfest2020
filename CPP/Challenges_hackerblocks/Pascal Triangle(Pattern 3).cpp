#include<iostream>

using namespace std;

int main()
{
     int n,i,j;
     cin>>n;

     int a[n][n];

     for(i=0;i<n;i++)
     {
          for(j=0;j<=i;j++)
          {
               if(i==0||j==i||j==0)
                    a[i][j]=1;
               else
                    a[i][j]=a[i-1][j-1]+a[i-1][j];
               cout<<a[i][j]<<" ";
          }
          cout<<"\n";
     }
}
