/*
Efficient way to find MSB (most significant bit)
For any integer value, we can find the most significant bit is an effective way. This is done using or operator along with a bitwise shift operator. This method can find the MSB in o(1) time complexity.

The size of the integer should be predefined to create the program.
*/
#include <stdio.h>
int findMSB(int x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x = x + 1;
    return (x >> 1);
}
int main()
{
    int x = 49;
    printf("The number is %d\n", x);
    int msb = findMSB(x);
    printf("MSB of the number is %d\n", msb);
}

/*
Output
The number is 49
MSB of the number is 32
*/
