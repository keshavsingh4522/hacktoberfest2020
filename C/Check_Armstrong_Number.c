#include <math.h>
#include <stdio.h>

int main() {
   int num, number, remainder, n = 0;
   float result = 0.0;

   printf("Enter an integer: ");
   scanf("%d", &num);

   number = num;

   for (number = num; number != 0; ++n) {
       number /= 10;
   }

   for (number = num; number != 0; number /= 10) {
       remainder = number % 10;

      result += pow(remainder, n);
   }

   if ((int)result == num)
    printf("%d is an Armstrong number.", num);
   else
    printf("%d is not an Armstrong number.", num);
   return 0;
}
