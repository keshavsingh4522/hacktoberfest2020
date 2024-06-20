#include<stdio.h>
int add (int *a, int *b)
{
    int sum, sub;
    int *pa = a;
    *pa = 100;
    int *pb = b;
    *pb = 200;

    printf("the value of a is %d\n", *pa);
    printf("the value of b is %d\n", *pb);

    sum = *pa + *pb;
    *pa = sum;
    printf("the sum of a & b is %d\n", *pa);

    sub = *pa - *pb;
    *pb = sub;
    printf("the sub of a & b is %d\n", *pb);

    return 0;
}
int main ()

{
    int a=10, b=20, sum;
    printf("the value of a is %d\n", a);
    printf("the value of b is %d\n", b);
    add(&a,&b);
}