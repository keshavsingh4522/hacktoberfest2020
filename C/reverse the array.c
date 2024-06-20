// print reverse the array 
#include<stdio.h>
#include<conio.h>

void main()
{
    int size, i, j, a[100], b[100];
    clrscr();

    printf("Enter the size of array : ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) 
    {
        printf("Enter element %d :", i);
        scanf("%d", &a[i]);
    }

    /*
     * Copying elements into array b starting from end of array a
     */

    for (i = size - 1, j = 0; i >= 0; i--, j++)
        b[j] = a[i];

    /*
     * Copying reversed array into original.
     * Here we are modifying original array, this is optional.
     */

    for (i = 0; i < size; i++)
        a[i] = b[i];

    printf("Reverse array is :\n");

    for (i = 0; i < size; i++)
        printf("%d\n", a[i]);

    getch();
}
