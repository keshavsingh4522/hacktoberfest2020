/*
write a program to insert an element at given position from an array.
*/


#include<stdio.h>
#include<conio.h>

int main()
{
	int arr[10],i,n,element,position,temp;

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

	temp=n;

	printf("\n\nEnter the position you to enter the Element:");
	scanf("%d",&position);

	printf("\nEnter the element you want to enter in the Array:");
	scanf("%d",&element);

	// for (i = 1; i <=n; i++)
	// {
	// 	if (i > position)
	// 	{
	// 		arr[i]=arr[i-1];
	// 	}
	// 	else
	// 	{
	// 		if (i == position)
	// 		{
	// 			arr[i]=element;
	// 		}
	// 		else
	// 		{
	// 			arr[i]=arr[i];
	// 		}	
	// 	}
	// }

	while(temp>=position)
	{
		arr[temp+1]=arr[temp];
		temp=temp-1;
	}
	arr[position]=element;
	n++;

	printf("\nArray after Inserting element:\n");
	for (i = 1; i <=n; i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}
