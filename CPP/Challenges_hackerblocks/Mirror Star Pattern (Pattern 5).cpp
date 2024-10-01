#include<iostream>

using namespace std;

int main()
{
     int i,j,n,k,x;
     cin>>n;

     for(i=1;i<=n;i++)
     {
          if(i<=(n/2)+1)
          {
               for(j=i;j<=n/2;j++)
                    cout<<"\t";
               for(j=1;j<=(2*i)-1;j++)
                    cout<<"*\t";
               k=n-2;
               x=1;
          }
          else
          {
               for(j=0;j<x;j++)
                    cout<<"\t";
               for(j=0;j<k;j++)
                    cout<<"*\t";
               x++;
               k-=2;
          }
          cout<<"\n";
     }
}
