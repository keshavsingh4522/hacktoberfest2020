#include <stdio.h>
int binarysearch(int search,int array[]);
int main()
{
   int c,n,search,array[100];
   printf("enter number of elements ");
   scanf("%d",&n);
   printf("enter elements in ascending order");
   for (c = 0; c < n; c++)
      scanf("%d",&array[c]);
   printf("enter value to search");
   scanf("%d", &search);
   binarysearch(search,array);
   return 0;
}
int binarysearch(int search,int array[]){
   int  first, last, middle;
   first = 0;
   last = sizeof(array)+1;
   middle = (first+last)/2;

   while (first <= last) {
      if (array[middle] < search)
         first = middle + 1;
      else if (array[middle] == search) {
         printf("%d found at location %d ", search, middle+1);
         break;
      }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }
   if (first > last)
      printf("not in the list", search);
}