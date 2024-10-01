//Sort Operations
//Copyright @Agarwal-Kritik
#include <stdio.h>
#include <stdlib.h>

void second(void)
{
	system("cls");
	printf("\n=====================================================================================================================================");
	printf("\n\t\t\t    __  ___           __      __                   __   __  __ ___ __ __  __   __  ___");
	printf("\n\t\t\t|_/|__)| | ||_/   /\\ / _  /\\ |__)|  | /\\ |     /| (__\\ |__)|__) | /  (_  /  \\ /__    /");
	printf("\n\t\t\t| \\| \\ | | || \\  /--\\\\__)/--\\| \\ |/\\|/--\\|__    |  __/ |__)|__) | \\____) \\__/ \\__)  / ");
	printf("\n=====================================================================================================================================\n");
}

void msort(void)
{
	void merge(int a[], int i1, int j1, int i2, int j2)
	{
		int temp[50];
		int i, j, k;
		i = i1;
		j = i2;
		k = 0;
		while (i <= j1 && j <= j2)
		{
			if (a[i] < a[j])
				temp[k++] = a[i++];
			else
				temp[k++] = a[j++];
		}
		while (i <= j1)
			temp[k++] = a[i++];
		while (j <= j2)
			temp[k++] = a[j++];
		for (i = i1, j = 0; i <= j2; i++, j++)
			a[i] = temp[j];
	}
	void mergesort(int a[], int i, int j)
	{
		int mid;
		if (i < j)
		{
			mid = (i + j) / 2;
			mergesort(a, i, mid);
			mergesort(a, mid + 1, j);
			merge(a, i, mid, mid + 1, j);
		}
	}
	int a[30], n, i;
	second();
	printf("\n\n\t\t\t\t\tWELCOME TO MERGE SORT WINDOW.\n");
	printf("\nEnter size of array: ");
	scanf("%d", &n);
	printf("\nEnter array elements:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	mergesort(a, 0, n - 1);
	printf("\nSorted array is:");
	for (i = 0; i < n; i++)
	{
		printf(" %d ", a[i]);
		if (i < n - 1)
			printf(",");
	}
}

void isort(void)
{
	int A[1000], a, b, c, tmp;
	second();
	printf("\n\n\t\t\t\t\tWELCOME TO INSERTION SORT WINDOW.\n");
	printf("\nEnter size of array: ");
	scanf("%d", &a);
	printf("\nEnter array elements:\n", a);
	for (b = 0; b < a; b++)
		scanf("%d", &A[b]);
	for (b = 1; b <= a - 1; b++)
	{
		for (c = b; c > 0 && A[c - 1] > A[c]; c--)
		{
			tmp = A[c];
			A[c] = A[c - 1];
			A[c - 1] = tmp;
		}
	}
	printf("\nSorted list in ascending order: ");
	for (b = 0; b <= a - 1; b++)
	{
		printf(" %d ", A[b]);
		if (b < a - 1)
			printf(",");
	}
}

void Qsort(void)
{
	void quicksort(int x[10], int ft, int lt)
	{
		int pvt, j, temp, i;
		if (ft < lt)
		{
			pvt = ft;
			i = ft;
			j = lt;
			while (i < j)
			{
				while (x[i] <= x[pvt] && i < lt)
					i++;
				while (x[j] > x[pvt])
					j--;
				if (i < j)
				{
					temp = x[i];
					x[i] = x[j];
					x[j] = temp;
				}
			}
			temp = x[pvt];
			x[pvt] = x[j];
			x[j] = temp;
			quicksort(x, ft, j - 1);
			quicksort(x, j + 1, lt);
		}
	}
	second();
	printf("\n\n\t\t\t\t\tWELCOME TO QUICK SORT WINDOW.\n");
	int x[20], size, i;
	printf("\nEnter size of array: ");
	scanf("%d", &size);
	printf("\nEnter array elements:\n", size);
	for (i = 0; i < size; i++)
		scanf("%d", &x[i]);
	quicksort(x, 0, size - 1);
	printf("\nSorted elements: ");
	for (i = 0; i < size; i++)
	{
		printf(" %d ", x[i]);
		if (i < size - 1)
			printf(",");
	}
}

void main()
{
	int k = 4;
	second();
	printf("\n\n\t\t\t\t\tWELCOME TO SORTING METHODS WINDOW.\n");
	printf("\n\t\t\t\tWhich operation you want to perform?");
	while (k > 0)
	{
		printf("\n\n\t\t\t\tMain Menu:");
		printf("\n\t\t\t\t1) Insertion Sort\n\t\t\t\t2) Merge Sort\n\t\t\t\t3) Quick Sort\n\t\t\t\tPress \"0\" to EXIT\n\n");
		printf("\n\t\t\t\tEnter your choice: ");
		scanf("%d", &k);
		if (k == 1)
			isort();
		else if (k == 2)
			msort();
		else if (k == 3)
			Qsort();
		else if (k == 0)
			exit(0);
		else
			printf("\n\t\t\t\t\t\tInvalid Input!\n");
	}
}