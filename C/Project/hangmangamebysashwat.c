#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>
#include <string.h>
/**********************************************************************
*                                                                     *
* Code written by P Sashwat.                                          *
* More information regarding this code and me can be found on my      *
* Linkedin Profile : https://www.linkedin.com/in/sashwat-p-1952471b1/ *
*                                                                     *
***********************************************************************/
char fileLoc[500]; // backup file location
void showLogo() {
      printf("--------------------------------------------\n");
      printf("| #  #   #   #   #  #### #   #   #   #   # |\n");
      printf("| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
      printf("| #### ##### # # # #  ## # # # ##### # # # |\n");
      printf("| #  # #   # #  ## #   # #   # #   # #  ## |\n");
      printf("| #  # #   # #   #  ###  #   # #   # #   # |\n");
      printf("--------------------------------------------\n\n");
}
void prn_galg(int i) {
 switch (i) {
     case 0 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("\n");
      printf("____________\n\n");
     break;
     case 1 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 2 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 3 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 4 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |\n");
      printf("  |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 5 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |    |\n");
      printf("  |    |\n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 6 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |   \\|\n");
      printf("  |    | \n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 7 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |   \\|/\n");
      printf("  |    | \n");
      printf("  |\n");
      printf("__|_________\n\n");
     break;
     case 8 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |   \\|/\n");
      printf("  |    | \n");
      printf("  |   /\n");
      printf("__|_________\n\n");
     break;
     case 9 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    O \n");
      printf("  |   \\|/\n");
      printf("  |    | \n");
      printf("  |   / \\\n");
      printf("__|_________\n\n");
     break;
     case 10 :
      printf("Amount of wrong letters: %d\n\n", i);
      printf("  _______\n");
      printf("  |/   | \n");
      printf("  |    X \n");
      printf("  |   \\|/\n");
      printf("  |    | \n");
      printf("  |   / \\\n");
      printf("__|_________\n\n");
     break;
 }
}
char randomNumber(int max_number) {
srand(time(NULL));
int g = (rand() % (max_number + 1));
return g;
}
char *getWord() {
  char c[50000];  // declare a char array
  int n;
  FILE *file;  // declare a FILE pointer
  // Opening words file
  if (strcmp(fileLoc, "") != 1) {
      // Here is the default words file, you can change this into whatever words file you'd like.
      file = fopen("words.txt", "r");
  } else {
      file = fopen(fileLoc, "r");
  }
  /* Incase the file can't be openend */
  if(file==NULL) {
    printf("An error has occured: can't open words file.\nPlease type the location of the words file:\n");
    scanf("%s", fileLoc);
    printf("Reading file '%s'.....\n\n", fileLoc);
    file = fopen(fileLoc, "r");
    if (file == NULL) {
    while (file==NULL) {
        printf("That file doesn't exist. Enter the location of the words file:\n");
        scanf("%s", fileLoc);
        printf("Reading file '%s'.....\n\n", fileLoc);
        file = fopen(fileLoc, "r");
     }
    }
    printf("File has been read.\n\n");
    n = fread(c, 1, 50000, file);
    c[n] = '\0';
  }  else {
    /* Reading the contents of the file */
    n = fread(c, 1, 50000, file);
    c[n] = '\0';
  }
    /* Separating the contents, divided by | and declaring variables */
    char *token = strtok(c, "|");
    char *words[200] = {0};
    int f = 0;
    while(token != NULL)
    {
      /* Allocating memory for the pointer */
      words[f] = malloc(strlen(token)+1);
      /* Copying entire string to pointer */
      strcpy(words[f],token);
      /* Resetting pointer */
      token = strtok(NULL, "|");
      f++;
    }
    /* Closing the file */
    fclose(file);
    /* Retrieving a random number */
    int wordN = randomNumber(f);
    /* Freeing all the memory allocated for the strings */
    int q;
    for(q  = 0; q < 200; q++)
    {
        if( q != wordN) {
         free(words[q]);
        }
    }
    /* Returning string */
    return words[wordN];
}
int main(void) {
char udi[] = "EMPTY";
while ((strcmp(udi, "END") != 0) && ((strcmp(udi, "AGAIN") == 0) || (strcmp(udi, "EMPTY") == 0))) {
 strcpy(udi, "EMPTY");
 /* Declaring variables */
 /* Random deciding which word is chosen to be guessed:
 guessWord is the word that needs to be guessed
 currentWord is the word that is filled with dots */
 /* Retrieving the word that matches with the wordNumber */
 /* Check which number was chosen: printf("%d", wordNumber); */
 char *tempWord = getWord();
 /* Declaring the guessWord with the length of dkljafoue */
 char guessWord[strlen(tempWord)+1];
 /* Copying the string of dkljafoue into guessWord */
 strcpy(guessWord, tempWord);
 /* Freeing the pointer */
 free(tempWord);
 /* Calculate the length of the guessWord */
 int wordlength = strlen(guessWord);
 /* Creating the dotword (name: currentWord) */
 char* currentWord = malloc( wordlength );
 int t;
 for (t = 0; t <= wordlength; t++) {
  if (t == wordlength) {
      currentWord[t] = '\0';
  } else {
      currentWord[t] =  '.';
  }
 }
 /* Currentword check: printf("Currentword: \"%s\"", currentWord); */
 /* Declaring variables */
 int errors = 0; /* Error amount, if its higher than 10 the loop stops */
 int guessedLetter = 0; /* Boolean Integer used to check wether the player entered a correct letter 0 = false, 1 = true */
 int i,n = 1;
 char c;
 /* Printing logo */
 showLogo();
 /* Printing introduction message */
 printf("%s\n\n%s\n%s\n%s\n%s\n\n%s%s\n\n",
 "Welcome to the Hangman game!",
 "The objective in this game is to guess the word.",
 "You can enter both uppercase and lowercase letters.",
 "If you think you know the word, you can type it in.",
 "You will loose if you have guessed 10 letters wrong.",
 "                                 -Made By P Sashwat.\n",
 "This is the word you need to guess: ",
 currentWord);
 printf("%d.     %s", n, "Enter the letter(s) you want to guess: ");
 /* As long as the word hasn't been guessed or the errors are lower than 10: */
 while( (strcmp(currentWord, guessWord) != 0) && (errors < 10) ){
 scanf("%c", &c); /* Retrieving the user entry */
 c = tolower(c); /* Removing caps */
 if (c != '\n') {
 if (isalpha(c)) { /* Making sure that the letter is alphanumeric */
 /* Checking wether the letter that has been entered (c) occurs in the guessWord */
 for (i = 0; i < wordlength; i++) {
  if (guessWord[i] == c) {
   currentWord[i] = c;
   guessedLetter = 1;
  }
 }
 /* Actions taken if the letter c doesn't occur in the guessWord and when it does */
 if (guessedLetter == 0) {
  errors++;
  printf("\nThat letter was incorrect.\n\n");
 } else {
 guessedLetter = 0;
  printf("\nThat letter was correct.\n\n");
 }
 /* Showing the galg and the amount of errors */
 printf("%s%s\n\n", "The word including the letters you guessed: ", currentWord);
 prn_galg(errors);
 n++; /* Increasing attempt amount */
 /* Showing header if the word has not been guessed and the errors are lower than 10 */
 if ( (strcmp(currentWord, guessWord) != 0) && (errors < 10) ) {
  printf("%d.     %s", n, "Enter the letter(s) you want to guess: ");
 }
 /* If the letter isn't alphanumeric (isalpha()) */
 } else {
  printf("Only alphanumeric symbols are allowed (a-z, A-Z), try again:\n");
 }
 }
 }
 /* Showing the results, wether the player won or not  */
 printf("---------------\n");
 printf("--- Results ---\n");
 printf("---------------\n\n");
 if (errors < 10) {
  if (strcmp(currentWord, guessWord) == 0) {
      printf("Congratulations you have guessed the right word!\n\n");
  } else {
      printf("You have guessed the wrong word, better luck next time!\n\n");
  }
 } else {
     printf("You have guessed the wrong word, better luck next time!\n\n");
 }
 printf("\nLetters guessed wrong: %d\nThe word that needed to be guessed: %s\nThe word you guessed: %s\n", errors, guessWord, currentWord);
 printf("\nEnter 'end' to end the game or enter 'again' to guess another word:\n");
 // Making sure that the user doesn't enter strange things
 while ((strcmp(udi, "END") != 0) && (strcmp(udi, "AGAIN") != 0)) {
  if (strcmp(udi, "EMPTY") != 0) {
      printf("\n\nIt is not allowed to enter anything else than 'again' or 'end', try again:\n");
  }
  // Retrieving the udi (udi = user determined input)
  scanf("%s", udi);
  // Converting the udi to uppercase
  int x;
  for (x = 0; x < 5; x++) {
      udi[x] = toupper(udi[x]);
  }
 }
 printf("\n\n--------------------------------------------\n\n");
}
return 0;
}
