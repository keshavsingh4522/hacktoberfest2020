#include <stdio.h>
int main()
{
	int a[10], n, i, t, element;
	printf("enter the number of values to be inserted");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("enter the value");
		scanf("%d", &a[i]);
	}
	printf("enter the element to be searched");
	scanf("%d", &element);
	for (i = 0; i < n; i++)
	{
		if (a[i] == element)
		{
			printf("yes");
			t = a[i];
			a[i] = a[i - 1];
			a[i - 1] = t;
			break;
		}
	}
	if (i == n)
		printf("no");
	else
	{
		for (i = 0; i < n; i++)
			printf("%d", a[i]);
	}
}

//sample o/p
//enter the number of values to be inserted7
//enter the value1
//enter the value2
//enter the value243
//enter the value3434
//enter the value668
//enter the value36836
//enter the value73
//enter the element to be searched7
//no
