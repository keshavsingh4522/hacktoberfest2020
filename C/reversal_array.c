#include<stdio.h>

int arrayrev(int a[])
{
    for (int i = 0; i < 7/2; i++)
    {
        int b = a[i];
        a[i] = a[6-i];
        a[6-i] = b;
    }
}
int arrayprint(int a[])
{
    for (int i = 0; i < 7; i++)
    {
        printf("%d\n",a[i]);
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {1,2,3,4,5,6,67};

    printf("the array before reversal is :\n");
    arrayprint(a);
    arrayrev(a);
    printf("the array after reversal is :\n");
    arrayprint(a);
    
    return 0;
}
