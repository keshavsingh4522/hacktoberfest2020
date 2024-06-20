#include<iostream>
using namespace std;
int m, n;
int create(int a[10][10])
{
int size;
cout<<" Enter the no. of rows and columns ";
cin>>m>>n;
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
cout<<"Enter the "<<i<<j<<" element of array ";
cin>>a[i][j];
if(a[i][j] != 0 )
{
size++;
}
}
}
return size;
}
void triplet(int s[10][10], int d[][3])
{
int k=0;
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
if(s[i][j] != 0 )
{
d[k][0]=i;
d[k][1]=j;
d[k][2]=s[i][j];
k++ ;
}
}
}
}
void display(int f[][3], int g)
{
for(int i=0;i<g;i++)
{
for(int j=0;j<3;j++)
{
cout<<f[i][j]<<" ";
}cout<<endl;
}
}
void addition(int h[10][10] , int l[10][10], int k)
{
int e[10][10], r[k][3], size;
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
e[i][j] = h[i][j] + l[i][j];
if(e[i][j] != 0 )
{
size++;
}
}
}
triplet(e,r);
display(r,size);
}
void multiplication(int h[10][10],int v[10][10], int k)
{
int pro[10][10], x[k][3], size;
for(int i=0;i<n;i++)
{
for(int l=0;l<m;l++)
{ int sum=0,sum1=0;
for(int j=0;j<m;j++)
{
sum1= h[i][j]*v[j][l];
sum=sum+sum1;
}
pro[i][l]=sum;
if(pro[i][l] != 0 )
{
size++;
}
}
}
triplet(pro,x);
display(x,size);
}
int main()
{
int q[10][10], w[10][10], row, row2;
 cout<<" Creating 1st Sparse Matrix"<<endl;
row = create(q);
int arr[row][3];
cout<<" Creating 2nd sparse matrix"<<endl;
row2 = create(w);
int arr2[row2][3];
cout<<" Converting 1st sparse matrix to triplet"<<endl;
triplet(q,arr);
display(arr,row);
cout<<" Converting 2nd sparse matrix to triplet"<<endl;
triplet(w,arr2);
display(arr2,row2);
cout<<" Addition of sparse matrices"<<endl;
addition(q,w,row);
 cout<<" Multiplication of sparse matrix"<<endl;
 multiplication(q,w,row);
return 0;
}