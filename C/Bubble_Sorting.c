#include<stdio.h>

int A[100] , n ,i , counter;	
void createArray();
void displaySteps();
void sortArray();
void showArray();

int main()
{	
	printf("\t\t\tHello friend\n");
	createArray();
	sortArray();
	showArray();
	printf("\n\t\t\tThank you");
	return 0;
}

void createArray()
{
	printf("  Enter the number of values to enter in the array : ");
	scanf("%d",&n);
	printf("\n  Enter the values in the array : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
}

void displaySteps()
{
	for(i=0;i<n;i++)
	{
		printf(" %d",A[i]);
	}
	printf("\n");
}

void sortArray()
{
	int temp;
	counter =1;
	printf("\n  Bubble sorting steps are : \n");
	while(counter<n)
	{
		displaySteps();
		for(i=0;i<n-counter;i++)
		{
			if(A[i]>A[i+1])
			{
				temp = A[i];
				A[i]=A[i+1];
				A[i+1]=temp;
			}
		}
		counter++;
	}
}

void showArray()
{
	printf("\n  Sorted Array values are : ");
	for(i=0;i<n;i++)
	{
		printf(" %d",A[i]);
	}
}
