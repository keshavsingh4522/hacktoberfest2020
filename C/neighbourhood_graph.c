#include <stdio.h>

int graph[4][3] = {{2, 3, 4}, {1, 3, 4}, {1, 2, 0}, {1, 2, 0}};

void checkNeighbour(int i, int j)
{
    int k, checkNeighbour = 0;

    for (k = 0; k < 3; k++)
    {
        if (graph[i][k] == j)
        {
            checkNeighbour = 1;
        }
    }
    printf("%d\t", checkNeighbour);
}

int main()
{
    int i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 1; j <= 4; j++)
        {
            checkNeighbour(i, j);
        }
        printf("\n");
    }
}