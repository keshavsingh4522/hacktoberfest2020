/*
Directly calculate the XOR of all numbers from 1 to n.
If we observe the XOR of 0 to n carefully we can derive a general pattern. Which is illustrated here
*/
#include <stdio.h>
// Direct XOR of all numbers from 1 to n
int findXORuptoN(int n)
{
    switch (n % 4)
    {
    case 0:
        return n;
    case 1:
        return 1;
        break;
    case 2:
        return n + 1;
        break;
    case 3:
        return 0;
        break;
    default:
        break;
    }
}
int main()
{
    int n = 9870;
    int xorupton = findXORuptoN(n);
    printf("XOR of all number up to %d is %d\n", n, xorupton);
}
/*
Output
XOR of all number up to 9870 is 9871
*/