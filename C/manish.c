#include <stdio.h>

int main() {
   //initialize a variable 
   int a, b, c, i, n;

   n = 4;

   a = b = 1;
   
   printf("%d %d ",a,b);

   for(i = 1; i <= n-2; i++) {
      c = a + b;
      printf("%d ", c);
      
      a = b;
      b = c;
   }
   
   return 0;
}
//Code is Created by Ujwal Gulhane 
