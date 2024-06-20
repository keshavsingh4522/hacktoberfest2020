#include<bits/stdc++.h> 
using namespace std;
void solve()
{
    int n,a[100][100],left,right,top,bottom,direction=0,m,counter = 1;
    cout<<"Enter Degree of Matrix\n";
    cin>>n;
    left = 0,right=n-1,top=0,bottom=n-1;
    while(left<=right && top<=bottom)
    {
        if(direction ==0)
        {
            for(int i=left;i<=right;i++)
            a[top][i] = counter++;
            top++;
        }
        else if (direction==1)
        {
             for(int i=top;i<=bottom;i++)
             a[i][right]=counter++;
             right--;
        }
        else if (direction==2)
        {  
            for(int i=right;i>=left;i--)
                a[bottom][i] = counter++;
                bottom--;
            
        }
        else 
        {
           for(int i=bottom;i>=top;i--)
                a[i][left]=counter++;
                left++;
        }
        direction = (direction+1)%4;
    }
   
   cout<<"The Elements of Matrix in Spiral Manner are\n";
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       cout<<a[i][j]<<" ";
       cout<<"\n";
   }
}
int main()
{
solve();
cout<<"\n";
return 0;
}
