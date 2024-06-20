#include<bits/stdc++.h>
using namespace std;
struct SparseMatrix{
    int row,col,elem;
};
void input(SparseMatrix sp[])
{
    int k=1,x;
    cout<<"Enter the order of matrix\n";
    cin>>sp[0].row>>sp[0].col;
    cout<<"Enter the Elements of Matrix\n";
    for(int i=0;i<sp[0].row;i++)
    for(int j=0;j<sp[0].col;j++)
    {
        cin>>x;
        if(x!=0)
        {
            sp[k].row=i,sp[k].col=j,sp[k].elem=x;
            k++;
        }
    }
    sp[0].elem=k;
}
void print(SparseMatrix sp[])
{   
    
    int k=1;
    for(int i=0;i<sp[0].row;i++)
  {  for(int j=0;j<sp[0].col;j++)
  {
      if(sp[k].row==i && sp[k].col==j)
      {cout<<sp[k].elem<<" ";
      k++;}
      else
      cout<<0<<" ";
    }
    cout<<"\n";
  }

}
void transpose(SparseMatrix sp[])
{
    int count[sp[0].col],index[sp[0].col+1];
    SparseMatrix spt[sp[0].elem];
    spt[0].row=sp[0].col,spt[0].col=sp[0].row,spt[0].elem=sp[0].elem;
    
    for(int i=0;i<sp[0].col;i++)
    count[i]=0;
   
    for(int i=1;i<sp[0].elem;i++)
    count[sp[i].col]++;
    index[0]=1;
    
    for(int i=1;i<sp[0].col;i++)
    index[i]=index[i-1]+count[i-1];

    for(int i=1;i<sp[0].elem;i++)
    {
        int pos = index[sp[i].col]++;
        spt[pos].col = sp[i].row;
        spt[pos].row=sp[i].col;
        spt[pos].elem=sp[i].elem;
    }
cout<<"Transpose is \n";
print(spt);

}
void solve()
{
    SparseMatrix sp[100];
    input(sp);
    transpose(sp);
}
int main()
{
solve();
return 0;
}
