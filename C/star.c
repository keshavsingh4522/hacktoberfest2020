#include<stdio.h>
#include<conio.h>
int main()
{
int n, s, i, j;
printf("Enter number of rows: ");
scanf("%d",&n);
for(i = 1; i <= n; i++)
{
//for loop for displaying space
for(s = i; s < n; s++)
{
printf(" ");
}
//for loop to display star equal to row number
for(j = 1; j <= (2 * i - 1); j++)
{
printf("*");
}
// ending line after each row
printf("\n");
}
}
