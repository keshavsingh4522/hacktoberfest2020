#include <stdio.h>

int main()
{
	float highscore[5];
	int x;

	for(x=0;x<5;x++)
	{
		printf("High score #%d: ",x+1);
		scanf("%f",&highscore[x]);
	}

	puts("Here are the high scores:");
	for(x=0;x<5;x++)
		printf("#%d %.2f\n",x+1,highscore[x]);

	return(0);
}

