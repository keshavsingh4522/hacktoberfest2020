#include <stdio.h>
int main()
{
   int n, temp, i, j;
   printf("Enter No of elements in the array \n");
   scanf("%d", &n);
   int number[n];
   printf("Enter the elements of array \n");
   for (int i = 0; i < n; i++)
      scanf("%d", &number[i]);
   for (i = n - 2; i >= 0; i--)
   {
      for (j = 0; j <= i; j++)
      {
         if (number[j] > number[j + 1])
         {
            temp = number[j];
            number[j] = number[j + 1];
            number[j + 1] = temp;
         }
      }
   }
   printf("Sorted elements: ");
   for (i = 0; i < n; i++)
      printf(" %d", number[i]);
   return 0;
}
