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
    sp = spt;

}
void multiplication(SparseMatrix a[],SparseMatrix b[])
{
   
      if(a[0].row!=b[0].col)
      {
          cout<<"Multiplication not possible\n";
      }
      else
      {
           int frow,fcol,sum=0,k=0,i,j,ii,jj;
    SparseMatrix c[100];
    c[0].row =a[0].row,c[0].col=b[0].col;
         for(int i=1;i<a[0].elem;i++)
         {
        frow=a[i].row;
        for(j=1;j<b[0].elem;j++)
            {
             fcol=b[j].col;
             sum=0;
            for(ii=1, jj=1; ii<a[0].elem && jj<b[0].elem && a[ii].row<=frow && b[jj].row<=fcol;)
            {
                if (a[ii].row != frow) ii++;
                if(b[jj].row != fcol) jj++;
                if (a[ii].row == frow && b[jj].row == fcol)
                    {
                        if (a[ii].col < b[jj].col) ii++;
                        else if (a[ii].col > b[jj].col) jj++;
                        else { sum = sum + (a[ii].elem*b[jj].elem); ii++; jj++;}
                    }
            }
            
            if(sum!=0) {c[k].row = frow; c[k].col = fcol; c[k].elem= sum; sum=0; k++;}
            
            while(j<b[0].elem-1 && b[j].row==fcol) j++;
        }
        
    while(i<a[0].elem && a[i].row==frow)     i++;
    
            
}
c[0].elem=k;
 cout<<"Multiplication is \n";
 print(c);
}
}
void solve()
{
    SparseMatrix a[100],b[100];
    input(a);
    input(b);
    multiplication(a,b);
}
int main()
{
solve();
return 0;
}
