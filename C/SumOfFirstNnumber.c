#include<stdio.h>

    int main(){
       int a;
       int i=0;
       int c=0;
       printf("enter the value of no till which required to be added\n");
       scanf("%d",&a);
       while (i<(a+1)){
          c=(c+i);
          i=i+1;
       }
       printf("result is %d",c);
       return 0;
    }

