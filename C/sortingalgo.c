//Write a C program to sort an array of n number of elements using bubble sort, selection sort, and insertion sort.
// Assume that n >5. Print the sorted output after each pass.

#include <stdio.h>

//function to print array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

//Function to sort an array using bubblesort algorithm
int bubblesort(int array[], int n)
{
    int temp, i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        printArray(array, n);
    }
    return 0;
}
//Function to sort an array using selectionsort algorithm
int selectionsort(int array[], int n)
{
    int min, i, j, temp;
    for (i = 0; i <= n - 2; i++)
    {
        min = i;
        for (j = i + 1; j <= n - 1; j++)
        {
            if (array[j] < array[min])
                min = j;
        }

        printArray(array, n);
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
    return 0;
}

//Function to sort an array using insertionsort algorithm
int insertionsort(int array[], int n)
{
    int temp, i, j;

    for (i = 1; i < n; i++)
    {
        temp = array[i];
        j = i - 1;

        while ((temp < array[j]) && (j >= 0))
        {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = temp;
        printArray(array, n);
    }

    return 0;
}

int main()
{
    int array[50] = {0};
    int n, sort;

    printf("How many numbers are you going to enter?");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the number %d:", i + 1);
        scanf("%d", &array[i]);
    }

    printArray(array, n);

    printf("Enter the SORT number you want to choose \n 1:Bubblesort \t 2:Selectionsort \t 3:Insertionsort)");
    scanf("%d", &sort);

    if (sort == 1)
        bubblesort(array, n);
    else if (sort == 2)
    {
        selectionsort(array, n);
        printArray(array, n);
    }
    else if (sort == 3)
        insertionsort(array, n);
    else
        printf("Invalid number");

    return 0;
}
