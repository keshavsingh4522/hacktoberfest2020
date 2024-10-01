#include <stdio.h>

int main()
{
    char menu;
    int num_first, num_two, result;
    printf(" ====================================\n");
    printf("     Calculator Program\n");
    printf(" ====================================\n\n");
    printf(" Menu :\n");
    printf(" \t[1] +\n");
    printf(" \t[2] -\n");
    printf(" \t[3] x\n");
    printf(" \t[4] /\n");
    printf(" \t[5] out\n\n");
    printf(" Chosee menu : ");
    scanf("%c",&menu);
    if(menu == '1')
    {
        printf("\n [1] + :\n");
        printf("     -------------------------------\n");
        printf("     Enter the first number: ");
        scanf("%d",&num_first);
        printf("     Enter the second number: ");
        scanf("%d",&num_two);
        result = num_first + num_two;
        printf("     ------------------------------- +\n");
        printf("     Result                    : %d", result);
    }
    else if(menu == '2')
    {
        printf("\n [2] - :\n");
        printf("     -------------------------------\n");
        printf("     Enter the first number : ");
        scanf("%d",&num_first);
        printf("     Enter the second number : ");
        scanf("%d",&num_two);
        result = num_first - num_two;
        printf("     ------------------------------- +\n");
        printf("     Result                    : %d", result);
    }
    else if(menu == '3')
    {
        printf("\n [3] Perkalian :\n");
        printf("     -------------------------------\n");
        printf("     Enter the first number : ");
        scanf("%d",&num_first);
        printf("     Enter the second number : ");
        scanf("%d",&num_two);
        result = num_first * num_two;
        printf("     ------------------------------- +\n");
        printf("     Result                    : %d", result);
    }
    else if(menu == '4')
    {
        printf("\n [4] / :\n");
        printf("     -------------------------------\n");
        printf("     Enter the first number : ");
        scanf("%d",&num_first);
        printf("     Enter the second number : ");
        scanf("%d",&num_two);
        result = num_first / num_two;
        printf("     ------------------------------- +\n");
        printf("     Result                    : %d", result);
    }
    else if(menu == '5')
    {
        exit(0);
    }
    else
    {
        printf(" The menu you selected is not listed.");
    }
    printf("\n\n ====================================\n");
    getch();
    return 0;
}
