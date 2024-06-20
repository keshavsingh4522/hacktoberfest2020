//An algorithm to generate all the prime numbers within an range.
#include <stdio.h>
#define size 1000

int main (void)
{
    int n;
    scanf("%d",&n);
    int arr[size]={0};

    for(int i=2;i*i<=n;i++)
    {
        for(int j=i;i*j<=n;j++)
        {
            arr[i*j]=1;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(!arr[i])
        printf("%d ",i);
    }
    return 0;
}
