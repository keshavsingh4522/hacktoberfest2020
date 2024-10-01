#include<stdio.h>
void main()
{
int i,j,n;
printf("Enter no of lines needed\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
	for(j=1;j<=i;j++)
	{
	printf("*");
	}
printf("\n");
}
}
