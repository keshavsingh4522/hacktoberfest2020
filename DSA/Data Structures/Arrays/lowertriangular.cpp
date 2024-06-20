#include<bits/stdc++.h>
using namespace std;
void solve()
{
     int n,x,k=0;
    cout<<"Enter the degree of the matrix \n";
    cin>>n;
    int a[2*n];
    cout<<"Enter elements\n";
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
      cin>>x;
      if(i>=j)
      a[k++]=x;

    }
    k=0;
    cout<<"Required Lower Triangular  matrix is\n";
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
    {
      
      if(i>=j)
      cout<<a[k++]<<" ";
      else
      cout<<0<<" ";

    }
    cout<<"\n";}

}
int main()
{
solve();
return 0;
}
