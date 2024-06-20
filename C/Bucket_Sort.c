// Bucket Sort in C programming

#include <stdio.h>
#include<stdlib.h>
int getMax(int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}
void bucketSort(int array[], int size)
{
    // The size of bucket must be at least the (max+1) but
    // we cannot assign declare it as int bucket(max+1) in C as
    // it does not support dynamic memory allocation.
    // So, its size is provided statically.
    
    int bucket[10];
    const int max = getMax(array, size);
    for (int i = 0; i <= max; i++)
    {
        bucket[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        bucket[array[i]]++;
    }
    for (int i = 0, j = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            array[j++] = i;
            bucket[i]--;
        }
    }
}
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}
int main()
{
    int data[] = {4, 3, 4, 5, 6, 0, 9, 5};
    int size = sizeof(data) / sizeof(data[0]);
    bucketSort(data, size);
    printf("Sorted array in ascending order: \n");
    printArray(data, size);
}
