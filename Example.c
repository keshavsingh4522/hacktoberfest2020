#include<stdio.h> // header files  
#include<conio.h>  
void main()  
{   // initialize the local variables.  
    int l =5, b=10, ar, pr;  
    printf("Length & Breadth of the rectangle is: %d & %d",l, b);  
    ar = l * b; // calculate area of rectangle.  
    pr = 2 * (l + b); // calculate perimeter of rectangle.  
    printf("\n Area of Rectangle is: %d", ar);  
    printf("\n Perimeter of Rectangle is: %d", pr);    
}   