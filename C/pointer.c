#include <stdio.h>
 
int main()
{
    int a[5] = {10,20,30,40,50};
    int *b = &a[5];
    printf("the address of a is %d\n", &a[0]);
    printf("the address of a is %d\n", &a[1]);
    printf("the address of a is %d\n", &a[2]);
    printf("the address of a is %d\n", &a[3]);
    printf("the address of a is %d\n", &a[4]);
    printf("the address of a is %d\n", a + 0);
    printf("the address of a is %d\n", a + 1);
    printf("the address of a is %d\n", a + 2);
    printf("the address of a is %d\n", a + 3);
    printf("the address of a is %d\n", a + 4);
    printf("the address of a is %d\n", *b);

    printf("the value at address of a is %d\n", a[0]);
    printf("the value at address of a is %d\n", a[1]);
    printf("the value at address of a is %d\n", a[2]);
    printf("the value at address of a is %d\n", a[3]);
    printf("the value at address of a is %d\n", a[4]);
    printf("the value at address of a is %d\n", *(&a[0]));
    printf("the value at address of a is %d\n", *(&a[1]));
    printf("the value at address of a is %d\n", *(&a[2]));
    printf("the value at address of a is %d\n", *(&a[3]));
    printf("the value at address of a is %d\n", *(&a[4]));

   return 0;
}