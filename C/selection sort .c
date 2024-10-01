#include <stdio.h>
int main(void)
{
	int a[100], n, i, j, b;
	printf("enter the number of values to be inserted");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("enter the value");
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
}

//sample o/p
//enter the number of values to be inserted5
//enter the value252
//enter the value78
//enter the value57
//enter the value09
//enter the value35
//252 78 57 35 9
