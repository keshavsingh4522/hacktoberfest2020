#include <stdio.h>
#include <conio.h>

int main()
{
    // declaration of the int type variable
    int arr[50];
    int pos, i, num; // declare int type variable
    printf(" \n Enter the number of elements in an array: \n ");
    scanf(" %d", &num);

    printf(" \n Enter %d elements in array: \n ", num);

    // use for loop to insert elements one by one in array
    for (i = 0; i < num; i++)
    {
        printf(" arr[%d] = ", i);
        scanf(" %d", &arr[i]);
    }

    // enter the position of the element to be deleted
    printf(" Define the position of the array element where you want to delete: \n ");
    scanf(" %d", &pos);

    // check whether the deletion is possible or not
    if (pos >= num + 1)
    {
        printf(" \n Deletion is not possible in the array.");
    }
    else
    {
        // use for loop to delete the element and update the index
        for (i = pos - 1; i < num - 1; i++)
        {
            arr[i] = arr[i + 1]; // assign arr[i+1] to arr[i]
        }

        printf(" \n The resultant array is: \n");

        // display the final array
        for (i = 0; i < num - 1; i++)
        {
            printf(" arr[%d] = ", i);
            printf(" %d \n", arr[i]);
        }
    }
    return 0;
}
