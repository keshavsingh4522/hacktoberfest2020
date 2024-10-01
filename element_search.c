#include<stdio.h>
#include<string.h>
int main()
{
int search[100],i,n,count=0,x;
printf("Enter the limit of array : ");
scanf("%d",&x);
printf("Enter the elements : ");
for(i=0;i<x;i++)
{
scanf("%d",&search[i]);
}
printf("Enter the element to be found : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
if(search[i]==n)
{
printf("The element %d found at the location %d",n,i);
++count;
}
}
if(count==0)
{
printf("Element not  found");
}
return 0;
}


