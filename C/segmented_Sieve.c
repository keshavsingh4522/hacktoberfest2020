//segmentedsieve

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
int main()
{
    int x;
    scanf("%d", &x);
    for (int y = 0; y < x; y++)
    {
        int n, high, low;
        scanf("%d %d", &low, &high);
        n = sqrt(high);
        int temp[n];
        bool prime[n + 1];
        memset(prime, true, n + 1);
        prime[1] = false;
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        int j = 0;
        for (int i = 2; i <= n; i++)
            if (prime[i] == true)
            {
                temp[j] = i;
                j++;
            }
        bool mark[high - low + 1];

        memset(mark, true, high - low + 1);
        if (low == 1)
            mark[0] = false;
        for (int i = 0; i < j; i++)

        {
            int p = temp[i];
            for (int i = p * p; i <= high; i += p)
            {
                if (i >= low)
                    mark[i - low] = false;
            }
        }

        for (int i = 0; i < high - low + 1; i++)
            if (mark[i] == true)
                printf("%d ", i + low);
        printf("\n");
    }
}
