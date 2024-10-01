/*
Flipping all bits of a number
We can flip all the bits of a number by subtracting it from a number whose all bits are set.

Number = 0110100
The number will all bits set = 1111111
Subtraction -> 1111111 - 0110100 = 1001011 (number with flipped bits)
*/
#include <stdio.h>
int main()
{
    int number = 23;
    int n = number;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    printf("The number is %d\n", number);
    printf("Number with reversed bits %d\n", n - number);
}

/*
The number is 23
Number with reversed bits 8
*/