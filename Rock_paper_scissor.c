
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int Game(char user_input, char AI_response)
{

	if (user_input== AI_response)
		return -1;


	if (user_input== 's' && AI_response == 'p')
		return 0;

			else if (user_input== 'p' && AI_response == 's') return 1;


	if (user_input== 's' && AI_response == 'z')
		return 1;

	
	else if (user_input== 'z' && AI_response == 's')
		return 0;

	
	if (user_input== 'p' && AI_response == 'z')
		return 0;

	else if (user_input== 'z' && AI_response == 'p')
		return 1;
}


int main()
{
	
	int n;

	char you, AI_response, result;

	
	srand(time(NULL));

	n = rand() % 100;

	if (n < 33)

	
		AI_response = 's';

	else if (n > 33 && n < 66)


		AI_response = 'p';
	else
		AI_response = 'z';

	printf("\n\n\n\n\t\t\t\tEnter 's' for STONE, 'p' for PAPER and 'z' for SCISSOR\n\t\t\t\t\t\t\t");

	scanf("%c", &you);

	result = Game(you, AI_response);

	if (result == -1) {
		printf("\n\n\t\t\t\tGame Draw!\n");
	}
	else if (result == 1) {
		printf("\n\n\t\t\t\tWow! You have won the game!\n");
	}
	else {
		printf("\n\n\t\t\t\tOh! You have lost the game!\n");
	}
		printf("\t\t\t\tYou choose : '%c' and Computer choose : '%c'\n", you, AI_response);

	return 0;
}
