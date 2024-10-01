#include <stdio.h>
main()
{
    int i,n,j,rd,ld;
    rd=ld=0;
    printf("enter no of rows and columns");
    scanf("%d",&n);

    int a[n][n];

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("enter a no:");
            scanf("%d",&a[i][j]);
        }
    }

    printf("Matrix is \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                ld=ld+a[i][j];
            if((i+j)==(n-1))
                rd=rd+a[i][j];
        }
    }
    printf("\nsum of left diagonal=%d",ld);
    printf("\nsum of right diagonal=%d",rd);
}
