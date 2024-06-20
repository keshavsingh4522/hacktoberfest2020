#include<stdio.h>

int function()
{
    static int a = 10;
    printf("the value of variable a is %d\n",a);
    a= a + 1;
    
    return 0;
}

int main(int argc, char const *argv[])
{
    function();
    function();
    
}