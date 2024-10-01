#include<iostream>

using namespace std;

int main()
{
     int i,j,k=1,n;
     cin>>n;

     for(i=1;i<=n;i++)
     {
          for(j=0;j<i;j++)
               cout<<k++<<"\t";
          cout<<"\n";
     }
}
