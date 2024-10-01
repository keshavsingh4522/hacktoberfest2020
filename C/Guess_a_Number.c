// This is going to be fun
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{

    int guess, number,attempt=1;
    srand(time(0));
    number=rand()%100+1; //generats random number from 1 to 100;

    // printf("the number is %d\n",number);

    // keep running the loop untill number is gussed

    // you and your friends will guess a number between 1 to 100 untill correct number is guessed 
    // the one who guesses in least no. of attempts is winner

    do                                  //program must run at least once so do loop is used hre
    {
        printf("Guess a number between 1 to 100:\n");
        scanf("%d", &guess);

        if(guess>number){
            printf("! Smaller Number please:\n");

        }
        else if(guess<number)
        {

            printf("! Greater number please:\n");
        }
        else{
            printf("*******your guess is correct******\nAnd you guessed it in %d attempts\n",attempt);
        }
        attempt++;


    } while (guess!=number);
    
    return 0;
}
