#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a=0,b=0;

    printf("the multiplication table of number is \n");
    scanf("%d",&a);

    do{
        printf("%d x %d = %d\n",a,b,a*b);
        b = b+1;
    }while (b<=10);
    
    return 0;
}
