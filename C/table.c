#include<stdio.h>

int main()
{
	int table;

	printf("Enter the number you want multiplication table of : \n", table);
	scanf("%d", &table);

	printf("Multiplication table of %d is :\n\n", table);
	
	printf("%d x 1 = %d\n",table, table*1);
	printf("%d x 2 = %d\n",table, table*2);
	printf("%d x 3 = %d\n",table, table*3);
	printf("%d x 4 = %d\n",table, table*4);
	printf("%d x 5 = %d\n",table, table*5);
	printf("%d x 6 = %d\n",table, table*6);
	printf("%d x 7 = %d\n",table, table*7);
	printf("%d x 8 = %d\n",table, table*8);
	printf("%d x 9 = %d\n",table, table*9);
	printf("%d x 10 = %d\n",table, table*10);

	return 0;
}
