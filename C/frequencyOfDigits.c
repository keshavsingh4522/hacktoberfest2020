#include <stdio.h>

int main()
{
    int n, a[100], c = 0, i, max = 0;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    printf("Enter the elements of array : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int j = 0; j < n; j++)
    {
        c = 0;
        for (i = 0; i < n; i++)
        {

            if (a[j] == a[i])
            {
                c++;
            }
        }

        printf("Frequency of %d : %d\n", a[j], c);
    }
    return 0;
}

// sample
/* 
    Enter the size of array : 5
    Enter the elements of array : 1
    2
    1
    2
    1
    Frequency of 1 : 3
    Frequency of 2 : 2
*/