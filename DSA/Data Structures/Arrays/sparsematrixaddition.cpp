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
void addition(SparseMatrix a[],SparseMatrix b[])
{
    if(a[0].row!=b[0].row && a[0].col!=b[0].col)
    cout<<"Addition is not possible\n";
    else
    {
        SparseMatrix c[a[0].elem+b[0].elem];
        int apos=1,bpos=1,x=1;
        c[0].row=a[0].row,c[0].col=a[0].col;
       while(apos<a[0].elem && bpos<b[0].elem)
       {
             if(a[apos].row>b[bpos].row || (a[apos].row ==b[bpos].row && a[apos].col>b[bpos].col))
             {
                 c[x].row=b[bpos].row,c[x].col=b[bpos].col,c[x].elem=b[bpos].elem;
                 bpos++;
             }
             else if (a[apos].row<b[bpos].row || (a[apos].row ==b[bpos].row && a[apos].col<b[bpos].col))
             {
                 c[x].row=a[apos].row,c[x].col=a[apos].col,c[x].elem=a[apos].elem;
                apos++;
             }
             else
             {
                   c[x].row=a[apos].row,c[x].col=a[apos].col,c[x].elem=a[apos].elem+b[bpos].elem;
                   apos++,bpos++;
             }
             x++;
       }
        while(apos<a[0].elem)
        {
             c[x].row=a[apos].row,c[x].col=a[apos].col,c[x].elem=a[apos].elem;
                apos++;
                x++;
        }
        while(bpos<b[0].elem)
        {
         c[x].row=b[bpos].row,c[x].col=b[bpos].col,c[x].elem=b[bpos].elem;
                bpos++;
                x++;
        }
        c[x].elem=x;
        cout<<"Addition is \n";
        print(c);

    }
}
void solve()
{
    SparseMatrix a[100],b[100];
    input(a);
    input(b);
    addition(a,b);
}
int main()
{

solve();
return 0;
}
