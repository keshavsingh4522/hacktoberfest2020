#include <stdio.h>
#include <stdlib.h>
int W[10], V[10], Wt = 6;
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int knapsack(int n)
{
    printf("\n");
    int i, w;
    int F[n + 1][Wt + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= Wt; w++)
        {
            if (i == 0 || w == 0)
            {
                F[i][w] = 0;
                printf("%d ", F[i][w]);
            }
            else if (W[i - 1] <= w)
            {
                F[i][w] = max(V[i - 1] + F[i - 1][w - W[i - 1]], F[i - 1][w]);
                printf("%d ", F[i][w]);
            }
            else
            {
                F[i][w] = F[i - 1][w];
printf("%d ",F[i][w]);
            }
        }
        printf("\n");
    }
    int value = F[n][Wt];
    printf("Selected packs:\n");
    while (n > 0)
    {
        if (F[n][Wt] != F[n - 1][Wt])
        {
            printf("Item %d with W = %d , V = %d\n", n, W[n - 1], V[n - 1]);
            Wt = Wt - W[n - 1];
        }
        n--;
    }
    return value;
}
void main()
{
    int n, i;
    printf("Enter the number of items selected \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the weigth and value of item %d:\n", i + 1);
        scanf("%d %d", &W[i], &V[i]);
    }
    int value = knapsack(n);
    printf("Max value: %d\n", value);
}