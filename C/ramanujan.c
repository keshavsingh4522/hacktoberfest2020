//a program to calculate the value of pi using ramanujan's formula 
//https://en.wikipedia.org/wiki/Pi
#include<stdio.h>
#include<math.h>

int factorial(int);

int main(){
    double x = (2*pow(2.0,1.0/2.0))/9801;
    double sum = 0;

    for (float k = 0; k <= 10; k++){
        sum += (factorial(4*k)*(26390*k+1103))/
        (pow(factorial(k),4)*(pow(396,4*k)));
    }

    printf("%.48lf",1/(x*sum));
    
}

int factorial(int n){
    int i,f=1;
    for(i=1;i<=n;i++){
        f=f*i;
    }
    return f;
}
