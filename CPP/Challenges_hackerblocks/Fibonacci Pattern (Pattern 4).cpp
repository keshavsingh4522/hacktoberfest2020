#include<iostream>

using namespace std;

int main()
{
     int n;
     long a,b,c;

     cin>>n;

     a=0;b=1;

     int i,j;

     for(i=1;i<=n;i++)
     {
          if(i==1)
          {
               cout<<"0";
          }
          else
          {
               for(j=1;j<=i;j++)
               {
                    cout<<b<<"\t";
                    c=b;
                    b=a+b;
                    a=c;
               }
          }
          cout<<"\n";
     }
}
