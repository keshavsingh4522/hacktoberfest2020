#include<iostream>

using namespace std;

int main()
{
     int n,i,j;
     cin>>n;

     for(i=1;i<=n;i++)
     {
          if(i==1)
               cout<<i;
          else
          {
               cout<<i<<"\t";
               for(j=1;j<=i-2;j++)
                    cout<<"0\t";
               cout<<i;
          }
          cout<<"\n";
     }
}
