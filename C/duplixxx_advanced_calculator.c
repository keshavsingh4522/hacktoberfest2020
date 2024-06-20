/* this is duplixx :i created the advanced calculator in c which helps the user to get the desired result */ 
#include <stdio.h>
#include <stdlib.h>
int main()
{
    double num1,num2;
    
    char op;
    printf("enter the first number:");   //the input numbers
    scanf("%lf", &num1);
    printf("enter second number:");    //the second input numbers
    scanf("%lf", &num2);
    printf("enter operator:");       //operator which user user want to use
    scanf(" %c", &op);
    if (op == '+')
    {
        printf("%f", num1 + num2);
    }
    else if (op == '-')
    {
        printf("%f", num1 - num2);
    }
    else if (op == '*')
    {
        printf("%f", num1 * num2);
    }
    else if (op=='/'){
        printf("%f", num1 / num2);
    }else{printf("NOTHING\ntry again plz");} 
    return 0;
}
