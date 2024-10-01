#include<iostream>

using namespace std;

int main()
{
     int n,i,j,k;
     cin>>n;

     k=n-2;

     for(i=1;i<=n;i++)
     {
          for(j=0;j<n-i;j++)
               cout<<" ";
          if(i==1)
          {
               for(j=0;j<n;j++)
                    cout<<"*";
               cout<<"\n";
               continue;
          }
          else if(i==n)
          {
               for(j=0;j<n;j++)
                    cout<<"*";
               break;
          }
          cout<<"*";
          for(j=0;j<k;j++)
               cout<<" ";
          cout<<"*";

          cout<<"\n";
     }
}
