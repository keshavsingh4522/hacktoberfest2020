#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int m,n,point,col_index;
    bool saddle_point ;
    cout<<"Enter order of Matrix\n";
    cin>>m>>n;
    int a[m][n];
    cout<<"Enter the elements of Array\n";
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    cin>>a[i][j];

    for(int i=0;i<m;i++)
    {  point=INT_MAX;
        
        for(int j=0;j<n;j++)
        {
            if(point>a[i][j])
            {
                point = a[i][j];
                col_index=j;
            }
        }
        saddle_point = true;
        
        for(int k=0;k<m;k++)
        if(a[k][col_index]>point)
        {
            saddle_point = false;
            break;
        }
        if(saddle_point)
        {cout<<"Saddle Point found "<<point<<"\n";
        break;}
    }
    if(!saddle_point)
    cout<<"Saddle Point not found\n";


}
int main()
{

solve();
return 0;
}
