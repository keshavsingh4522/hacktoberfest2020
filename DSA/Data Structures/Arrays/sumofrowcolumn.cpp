#include<iostream>
using namespace std;
void solve()
{
    int m,n,rowsum,colsum;
    cout<<"Enter order of matrix\n";
    cin>>m>>n;
    int a[m][n];
    cout<<"Enter elements\n";
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    cin>>a[i][j];
    for(int i=0;i<m;i++)
    {
        rowsum=0;
        for(int j=0;j<n;j++)
        rowsum+=a[i][j];
        cout<<"Sum of Row "<<i+1<<" is:"<<rowsum<<"\n";
    }
    for(int i=0;i<n;i++)
    {
        rowsum=0;
        for(int j=0;j<m;j++)
        rowsum+=a[j][i];
        cout<<"Sum of Column "<<i+1<<" is:"<<rowsum<<"\n";
    }
}
int main()
{
solve();
return 0;
}
