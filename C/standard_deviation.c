#include <stdio.h>
#include <math.h>

void main()
{
  float Price[50];
  int  i, Number;
  float Mean, Variance, SD, Sum=0, Differ, Varsum=0;

  printf("\nPlease Enter the N Value\n");
  scanf("%d", &Number);

  printf("\nPlease Enter %d real numbers\n",Number);
  for(i=0; i<Number; i++)
   {
     scanf("%f", &Price[i]);
   }

  for(i=0; i<Number; i++)
   {
     Sum = Sum + Price[i];
   }
  
  Mean = Sum /(float)Number;

  for(i=0; i<Number; i++)
   {
     Differ = Price[i] - Mean;
     Varsum = Varsum + pow(Differ,2);
   }
  
  Variance = Varsum / (float)Number;
  SD = sqrt(Variance);
  
  printf("Mean               = %.2f\n", Mean);
  printf("Varience           = %.2f\n", Variance);
  printf("Standard deviation = %.2f\n", SD);
}
