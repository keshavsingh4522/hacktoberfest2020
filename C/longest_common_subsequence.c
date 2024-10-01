#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{

    int a[101], b[101], k, res[101];
    int lcs[102][102] = {0};
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (i = 0; i < m; ++i)
        scanf("%d", &b[i]);
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
        {
            if (a[i] == b[j])
                lcs[i + 1][j + 1] = lcs[i][j] + 1;
            else
                lcs[i + 1][j + 1] = max(lcs[i + 1][j], lcs[i][j + 1]);
        }

    k = lcs[n][m];
    i = n;
    j = m;
    while (lcs[i][j])
    {
        if (a[i - 1] == b[j - 1])
        {
            res[--k] = a[i - 1];
            --i;
            --j;
        }
        else
        {
            if (lcs[i - 1][j] > lcs[i][j - 1])
                --i;
            else
                --j;
        }
    }

    for (i = 0; i < lcs[n][m]; ++i)
        printf("%d ", res[i]);

    return 0;
}