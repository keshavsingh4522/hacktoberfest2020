#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int i,n,search;
printf("Enter number of elements : ");
scanf("%d",&n);
int a[n];
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
  printf("\nFound at %d .",i+1);
  break;
  }
 }
if(i==n)
 {
 printf("\nElement not found.");
 }
getch();
}
