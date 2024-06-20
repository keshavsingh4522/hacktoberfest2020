#include<stdio.h>
int main()
{
    int a; 
    printf("Which of the subjects have you passed? \n");
    printf("Type 1 for maths, 2 for Science, 3 for both maths and science \n");
    scanf("%d", &a);


    if(a == 1){
        printf("Wow!, you have won the prize of Rs15 for clearing the exam of Maths\n");
    }
    else if(a == 2){
        printf("Wow!, you have won the prize of Rs15 for clearing the exam of Science\n");
    }
    else if(a == 3){
        printf("Wow!, you have won the prize of Rs45 for clearing the exam of Maths and Science\n");
    }
    else
    {
        printf("Sorry! this choice is not given please select from the above given options.\n");
    }
    
    return 0; 
}