//swapping without using 3rd variable
//xor bitwise operator
#include <stdio.h>
int main()
{
    int a, b;
    printf("Enter value of a:");
    scanf("%d", &a);
    printf("Enter value of b:");
    scanf("%d", &b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("After swapping:\na=%d", a);
    printf("\nb=%d", b);
}
