#include <stdio.h>
#include <time.h>
int a, b, u, v, n, i, j, ne = 1, st, et;
int visited[10] = {0}, min, mincost = 0, cost[10][10];
void main()
{
  printf("Enter the number of nodes:");
  scanf("%d", &n);
  printf("Enter the adjacency matrix: ");
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
    {
      scanf("%d", &cost[i][j]);
      if (cost[i][j] == 0)
        cost[i][j] = 999;
    }
  st = clock();
  visited[1] = 1;
  printf("n");
  while (ne < n)
  {
    for (i = 1, min = 999; i <= n; i++)
      for (j = 1; j <= n; j++)
        if (cost[i][j] < min)
          if (visited[i] != 0)
          {
            min = cost[i][j];
            a = u = i;
            b = v = j;
          }
    if (visited[u] == 0 || visited[v] == 0)
    {
      printf("Edge %d:(%d %d) cost:%d", ne++, a, b, min);
      mincost += min;
      visited[b] = 1;
    }
    cost[a][b] = cost[b][a] = 999;
  }
  printf("Minimun cost=%d", mincost);
  et = clock();
  printf("Start Time =%d\nEnd Time =%d", st, et);
}
