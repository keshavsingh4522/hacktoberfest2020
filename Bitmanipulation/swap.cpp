/*
Swap two number (using bitwise XOR)
We can swap two values using the bitwise XOR operator. The implementation is −
*/
#include <stdio.h>
int main(){
   int x = 41;
   int y = 90;
   printf("Values before swapping! \n");
   printf("x = %d \t", x);
   printf("y = %d \n", y);
   x = x ^ y;
   y = y ^ x;
   x = x ^ y;
   printf("Values after swapping! \n");
   printf("x = %d \t", x);
   printf("y = %d \n", y);
   return 0;
}
/*
Output
Values before swapping!
x = 41 y = 90
Values before swapping!
x = 90 y = 41
*/
