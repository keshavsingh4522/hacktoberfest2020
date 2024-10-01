#include<stdio.h>

int factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n - 1);
}

void main(){
    printf("%d", factorial(5));
}
