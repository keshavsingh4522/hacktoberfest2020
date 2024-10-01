#include <stdio.h>
void main()
{
int a[25][25],b[25][25],c[25][25],i,j,k,r,s;
int m,n;
printf("Enter the first matrix\n");
scanf("%d%d",&m,&n);
printf("Enter the second matrix\n");
scanf("%d%d",&r,&s);
if(m!=r)
printf("\n The matrix cannot multiplied");
else
{
printf("\n Enter the elements of first matrix ");
for(i= 0;i<m;i++)
{
for(j=0;j<n;j++)
scanf("\t%d",&a[i][j]);
}
printf("\n Enetr the elements of second matrix ");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
scanf("\t%d",&b[i][j]);
}
printf("\n The element of first matrix is");
for(i=0;i<m;i++)
{
printf("\n");
for(j=0;j<n;j++)
printf("\t%d",a[i][j]);
}
printf("\n The element of second matrix is");
for(i=0;i<m;i++)
{
printf("\n");
for(j=0;j<n;j++)
printf("\t%d",b[i][j]);
}
for(i=0;i<m;i++)
{
printf("\n");
for(j=0;j<n;j++)
{
c[i][j]=0;
for(k=0;k<m;k++)
c[i][j]=c[i][j]+a[i][k]*b[k][j];
}
}
}
printf("\n Multiplication of two matrix is");
for(i=0;i<m;i++)
{
printf("\n");
for(j=0;j<n;j++)
printf("\t%d",c[i][j]);
}
}