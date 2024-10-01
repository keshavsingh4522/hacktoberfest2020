#include <stdio.h>
#include <stdlib.h>
int merge(int arr[], int l, int m, int r)
{
    int i, j, k, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        c1++;
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
        c2++;
    }
    L[n1] = 2147483647;
    R[n2] = 2147483647;
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            c3++;
            arr[k] = L[i];
            i++;
        }
        else
        {
            c4++;
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        c5++;
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        c6++;
        j++;
        k++;
    }
    return c1 + c2 + c3 + c4 + c5 + c6;
}
int mergeSort(int arr[], int l, int r, int c1, int c2)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        c1 += 1;
        mergeSort(arr, l, m, c1, c2);
        c2 += 1;
        mergeSort(arr, m + 1, r, c1, c2);
        int c = merge(arr, l, m, r);
        return c1 + c2 + c;
    }
}
void printArray(int A[], int s)
{
    for (int i = 0; i < s; i++)
        printf("%d ", A[i]);
    printf("\n");
}
void descending(int number[], int n)
{
    int i, j, a;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (number[i] < number[j])
            {
                a = number[i];
                number[i] = number[j];
                number[j] = a;
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand();
    int c = mergeSort(arr, 0, n - 1, 0, 0);
    printf("\nArray after sorting:\n");
    printArray(arr, n);
    c = 0;
    c = mergeSort(arr, 0, n - 1, 0, 0);
    printf("Time complexity for ascending data: %d\n", c);
    descending(arr, n);
    printArray(arr, n);
    c = 0;
    c = mergeSort(arr, 0, n - 1, 0, 0);
    printf("Time complexity for descending data: %d\n", c);
    return 0;
}
