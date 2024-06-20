#include <stdio.h>

int main()
{
    int a, b;
    int d[3][3], e[3][3], f[3][3];

    printf("enter the first matrix :\n");

    for (a = 0; a < 3; a++)
    {
        for (b = 0; b < 3; b++)
        {
            scanf("%d", &d[a][b]);
        }
    }

    printf("enter the second matrixs are :\n");

    for (a = 0; a < 3; a++)
    {
        for (b = 0; b < 3; b++)
        {
            scanf("%d", &e[a][b]);
        }
    }

    printf("the sum of matrixs are :\n");

    for (a = 0; a < 3; a++)
    {
        for (b = 0; b < 3; b++)
        {
            f[a][b] = (d[a][b] + e[a][b]);
            printf("%d\t", f[a][b]);
        }
        printf("\n");
    }
    return (0);
}
