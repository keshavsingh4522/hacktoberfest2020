#include <stdio.h>
int main()
{
	int n, i, max, min, a[100];
	printf("Enter total number of elements:");
	scanf("%d", &n);
	printf("Enter values:");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	max = a[0];
	min = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	printf("Maximum element: %d\n", max);
	printf("Minimum element: %d", min);
	return 0;
}
