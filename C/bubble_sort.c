#include<stdio.h>
void swap(int *x,int *y)///swapping function
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void bubblesort(int number[],int n)///Bubble sort function
{
   for(int i=0;i<n-1;i++)
   {
      for(int j=0;j<n-i-1;j++)
      {
        if(number[j]>number[j+1])
        {
          swap(&number[j],&number[j+1]);
        }
      }
   }
}
int main()//main drive
{
    int n, temp, i, j;
    printf ("Enter Number of data for array \n");//
    scanf("%d",&n);
    int number[n];
    printf ("Enter the data of array \n");
    for(int i=0;i<n;i++)
    {
       scanf("%d",&number[i]);
    }
    bubblesort(number,n);///bubblesort function call
    printf("Sorted elements: ");
    for(i=0;i<n;i++)
    printf(" %d",number[i]);///sorted array print
}
