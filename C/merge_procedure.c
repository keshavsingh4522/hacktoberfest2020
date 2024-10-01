#include<stdio.h>
int a[20],b[20];int i=0,j=0,k=0;int c[40];int m=0;int n=0;int x=0;int y=0;
void main()
{
    printf("Enter the size of the first array");
    scanf("%d",&m);
    printf("Enter the first array\n");
    for(x=0;x<m;x++)
    {
        scanf("%d",&a[x]);
    }
    printf("Enter the size of second array");
    scanf("%d",&n);
    printf("Enter the second array\n");
    for(y=0;y<n;y++)
    {
        scanf("%d",&b[y]);
    }
    while(i<m&&j<n)
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
            k++;
        }
        else
        {
            c[k]=b[j];
            j++;
            k++;
        }

    }
    while(i<m)
    {
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<n)
    {
        c[k]=b[j];
        j++;
        k++;
    }
    printf("The array is-\n");
    for(x=0;x<m+n;x++)
    {
        printf("%d ",c[x]);
    }
}
