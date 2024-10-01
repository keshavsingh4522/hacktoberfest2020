#include <stdio.h>
int Fact(int n)
{
    if(n==0||n==1)
      return 1;
    else if(n>1)
      return n*Fact(n-1);
}
int main()
{
int n;
printf("Enter a no. to get its factorial value: ");
scanf("%d",&n);
printf("Factorial value of %d: %d",n,Fact(n));
}