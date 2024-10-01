#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int i,n,a[100],search;
printf("Enter number of elements : ");
scanf("%d",&n);
printf("\nEnter %d elements : \n",n);
for(i=0;i<n;i++)
 {
 scanf("%d",&a[i]);
 }
printf("\nEnter element to be searched : ");
scanf("%d",&search);
for(i=0;i<n;i++)
 {
 if(a[i]==search)
  {
  printf("\nFound at %d .",m+1);
  break;
  }
 }
if(i==n)
 {
 printf("\nElement not found.");
 }
getch();
}
