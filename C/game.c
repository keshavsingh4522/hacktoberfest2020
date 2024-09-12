// A simple console-based game where the user choses a number from given options and then the program correctly guesses it based on a clue 


#include <stdio.h>
int main()
{
    int code;
    printf("We offer you a game to play\n");
    printf("Press 1 to play the game\n");
    printf("Press 0 to exit\n");
    scanf("%d",&code);
    if(code == 0)
    return 0;
    else if(code ==1)
    {
    int i, sum=0,num;
    printf("MATRIX 1:\t\t\t\tMATRIX 2:\n");
    printf("8\t9\t10\t11\t\t4\t5\t6\t7\n");
    printf("12\t13\t14\t15\t\t12\t13\t14\t15\n");
    printf("\nMATRIX 3:\t\t\t\tMATRIX 4:\n");
    printf("2\t3\t6\t7\t\t1\t3\t5\t7\n");
    printf("10\t11\t14\t15\t\t9\t11\t13\t15\n");
    printf("pick a number in your mind from any of the given given matrices:\n");
    printf("In how many matrices ,does your number appear into:  ");
    scanf("%d",&num);
    printf("enter the name(1/2/3/4) of those matrices:  ");
    int p[num];
    for(i=0;i<num;i++)
    scanf("%d",&p[i]);
    for(i=0;i<num;i++)
    {
        if(p[i]==1)
        sum = sum + 8;
        
        if(p[i]==2)
        sum = sum +4;
        
        if(p[i]==3)
        sum = sum +2;
        
        
        if(p[i]==4)
        sum = sum +1;
    }
    printf("you chose the number %d\n",sum);
    return 0;
    }
}


