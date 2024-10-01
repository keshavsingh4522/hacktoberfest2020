#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a, num,cnt=0;
    srand(time(0));
    num = rand() % 100 + 1;
    printf("Guess the number between 1 to 100 = ");
    scanf("%d", &a);
     while(1==1)
    {
        if(a>num)
        {
            printf("Please guess any lower number = ");
            scanf("%d",&a);
            cnt++;
        }
         else if(a<num)
        {
            printf("Please guess any higher number = ");
            scanf("%d",&a);
            cnt++;
        }
        else
        {
            printf("Hurray!!!!\n");
            printf("The Number is = %d\n",num);
            printf("Number of chances taken= %d",cnt+1);
             return 0;
        }
    }

   
}

