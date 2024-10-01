#include<stdio.h>

int sum(int n);

    int main(){
        int a;
        printf("Enter the number till which the sum has to be calculated\n");
        scanf("%d", &a);
        printf("The sum of %d natural numbers is %d\n", a, sum(a));
        return 0;
    }

int sum(int n){
if(n==0){
    return 0;
}
    else{
        return n * (n+1)/2;
    }
}

