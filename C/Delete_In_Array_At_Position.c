/*
write a program to delete an element at given position from an array.
*/

#include<stdio.h>
#include<conio.h>

int main()
{
	int arr[10],i,n,position,temp;

	printf("Enter the Numbers of Elements:");
	scanf("%d",&n);

	printf("\nEnter the elements of array:\n");
	for (i = 1; i <=n; i++)
	{
		printf("Enter value of arr[%d]:",i);
		scanf("%d",&arr[i]);
	}

	printf("\nArray Entered by user are:\n");
	for (i = 1; i <=n; i++)
	{
		printf("%d\t",arr[i]);
	}

	printf("\n\nEnter the position you to delete the Element:");
	scanf("%d",&position);

	temp=position;

	while(temp<=n-1)
	{
		arr[temp]=arr[temp+1];
		temp=temp+1;
	}
	n--;

	printf("\nArray after Deleting element:\n");
	for (i = 1; i <=n; i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}
