#include<stdio.h>

int arr(int a[5], int b[5])
{
    printf("the value of first array is :\n");
        for (int i = 0; i < 5; i++)
    {
        printf("%d\n",a[i]);
    }

    printf("the value of second array is :\n");
        for (int i = 0; i < 5; i++)
    {
        printf("%d\n",b[i]);
    }

    return 0;
}
int main(int argc, char const *argv[])
{
    int a[5],b[5];

    printf("enter the value of first array is :\n");
        for (int i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("enter the value of second array is :\n");
        for (int i = 0; i < 5; i++)
    {
        scanf("%d",&b[i]);
    }
    
    arr(a,b);    
    
    return 0;
}