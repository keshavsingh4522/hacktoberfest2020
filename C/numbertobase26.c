#include<stdio.h>
#include<stdlib.h>  
int main()
{
	int a[256], n, i=0;
	system("cls");
	printf("Enter the number: ");
	scanf("%d", &n);
		do
		{
			a[i] = n % 26;
			n = n/26;
			i++;
		}while(n!=0);
		printf("\nOutput is: ");
		for (i = i - 1; i >= 0; i--)
		{
			printf("%c", (char)(a[i] + 97));
		}
	return 0;
}
