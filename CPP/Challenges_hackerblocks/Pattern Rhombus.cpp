#include<iostream>

using namespace std;

int main()
{
     int i,j,n,k,x;
     cin>>n;

     for(i=1;i<=(2*n)-1;i++)
     {
          if(i<=n)
          {
               for(j=0;j<n-i;j++)
                    cout<<"\t";
               for(j=i;j<2*i;j++)
                    cout<<j<<"\t";
               for(j=2*i-2;j>=i;j--)
                    cout<<j<<"\t";
               k=n-1;
          }
          else
          {
               x=i;
               i=k;
               for(j=0;j<n-i;j++)
                    cout<<"\t";
               for(j=i;j<2*i;j++)
                    cout<<j<<"\t";
               for(j=2*i-2;j>=i;j--)
                    cout<<j<<"\t";
               k--;
               i=x;
          }
          cout<<"\n";
     }
}
