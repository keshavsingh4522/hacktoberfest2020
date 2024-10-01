#include<stdio.h>
int sum(int n)
{
    if(n==1)
    return 1;
    else
    return n+sum(n-1);
}
int main()
{
    int n;
    printf("Enter the value of no till which required to be added\n\n");
    scanf("%d",&n);
    printf("The sum of first %d is %d",n,sum(n));
}
