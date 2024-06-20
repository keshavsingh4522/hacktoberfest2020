#include <stdio.h>

int numPrint(int);
int main()
{
    int d;
    int abc;

    printf("enter the n number :\n");
    scanf("%d", &d);
	printf("\n\n Recursion : print the sum of numbers from 1 to n :\n");
	printf("-------------------------------------------------\n"); 

    abc = numPrint(d);
    printf("the sum of numbers are %d : %d\n", d, abc);
    return (0);
}

int numPrint(int n)
{
    int ad;
    if (n == 0)
    {
        return (1);
    }
    else
    {
        ad = n + numPrint(n - 1);
    }
        return (ad);
}