#include<stdio.h>
void print_array(int a[], int n);
int main()
{
	int n, i, j, count = 0, sum_d;
	printf("Enter the number of rows of a square matrix :- \n");
	scanf("%d", &n);
	int arr[n][n], sum_r[n], sum_c[n];
	printf("Enter the numbers :-\n");
	for( i = 0; i < n; i++)
		for( j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	printf("The entered matrix :-\n");
	for( i = 0; i < n; i++)
	{
		for( j = 0; j < n; j++)
			printf("%d\t", arr[i][j]);
		printf("\n");	
	}
	// Sum of rows
	for(i = 0; i < n; i++)
	{
		sum_r[i] = 0;
		for(j = 0; j < n; j++)
			sum_r[i] = sum_r[i] + arr[i][j];
	}
	// Sum of columns
	for(j = 0; j < n; j++)
	{
		sum_c[j] = 0;
		for(i = 0; i < n; i++)
			sum_c[j] = sum_c[j] + arr[i][j];
	}
	// Sum of diagonals
	sum_d = 0;
	for(i = 0; i < n; i++)		
		for(j = 0; j < n; j++)
			if(i == j)
				sum_d = sum_d + arr[i][j];
	
	// Print sum of rows;
	printf("Sum of rows :- ");
	print_array(sum_r, n);
	// Print sum of columns;
	printf("\nSum of columns :- ");
	print_array(sum_c, n);
	// Print the diagonal sum.
	printf("\nSum of diagonal :- %d", sum_d);
	
	// Check whether the matrix is magic square or not.
	for (i = 0; i < n; i++)
	{
		if(sum_r[i] != sum_c[i])
		{
			printf("\nMatrix is not a magic square.");
			break;
		}
		if((sum_r[i] == sum_c[i]) & (sum_r[i] == sum_d))
			count = count + 1;			
	}
	if(count == n)
		printf("\nMatrix is a magic square.");	
	return 0;
}
void print_array(int a[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d\t", a[i]);
}
