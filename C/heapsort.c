#include <stdio.h>
int main()
{
int h[20],num,i,j,root,t,x;
printf("Enter number of elements :");
scanf("%d", &num);
printf("\nEnter the elements : ");
for (i = 0; i < num; i++)
scanf("%d", &h[i]);
// build max heap
for(i=0;i<num;i++)
{
x=i;
do
{
root = (x - 1) / 2;
if (h[root] < h[x])
{
t = h[root];
h[root] = h[x];
h[x] = t;
}
x = root;
} while (x != 0);
}
printf("Heap array formed is: ");
for (i = 0; i < num; i++)
printf("%d\t ", h[i]);
for (j = num - 1; j >= 0; j--)
{
t = h[0];
h[0] = h[j];
h[j] = t;
root = 0;
do
{
x = 2 * root + 1;
if ((h[x] < h[x + 1]) && x < j-1)
x++;
if (h[root]<h[x] && x<j)
{
t = h[root];
h[root] = h[x];
h[x] = t;
}
root = x;
} while (x < j);
}
printf("\nThe sorted array is : ");
for (i = 0; i < num; i++)
printf("\t %d", h[i]);
}
