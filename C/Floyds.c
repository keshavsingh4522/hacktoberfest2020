#include <stdio.h>
#include <time.h>
#include <math.h>
int mat[10][10], d_mat[10][10], n;
void Floyd()
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            d_mat[i][j] = mat[i][j];
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (d_mat[i][j] > (d_mat[i][k] + d_mat[k][j]))
                    d_mat[i][j] = (d_mat[i][k] + d_mat[k][j]);
            }
        }
    }
}

void main()
{
    clock_t start, end;
    double t;
    int i, j;
    printf("Enter the total number of routes:\n");
    scanf("%d", &n);
    printf("Enter the connection between the house and the firestation in an matrix representation:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    start = clock();
    Floyd(mat);
    end = clock();
    printf("The Shortest path Matrix is \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", d_mat[i][j]);
        }
        printf("\n");
    }
    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time required : %f\n", t);
}