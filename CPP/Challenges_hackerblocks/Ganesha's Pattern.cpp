#include<iostream>

using namespace std;

int main()
{
     int n;
     cin>>n;

     int i,j;

     for(i=0;i<n;i++)
     {
          if(i==0)
          {
               cout<<"*";
               for(j=0;j<(n-3)/2;j++)
                    cout<<" ";
               for(j=0;j<=n/2;j++)
                    cout<<"*";
          }
          else if(i==n/2)
          {
               for(j=0;j<n;j++)
                    cout<<"*";
          }
          else if(i==n-1)
          {
               for(j=0;j<=n/2;j++)
                    cout<<"*";
               for(j=0;j<(n-3)/2;j++)
                    cout<<" ";
               cout<<"*";
          }
          else if(i<n/2)
          {
               cout<<"*";
               for(j=0;j<(n-3)/2;j++)
                    cout<<" ";
               cout<<"*";
          }
          else if(i>n/2)
          {
               for(j=0;j<n/2;j++)
                    cout<<" ";
               cout<<"*";
               for(j=0;j<(n-3)/2;j++)
                    cout<<" ";
               cout<<"*";
          }
          cout<<"\n";
     }
}
