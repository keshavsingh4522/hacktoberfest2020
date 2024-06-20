#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a, b, c, d;

    printf("press 0 for star pattern\n");
    printf("press 1 for reversal star pattern\n");
    scanf("%d", &d);
    printf("enter the numbers of rows you want to print\n");
    scanf("%d", &a);

    switch (d)
    {
    case 0:
        for (b = 0; b < a; b++)
        {
            for (c = 0; c <= b; c++)
            {
                printf("*");
            }
            printf("\n");
        }
        break;

    case 1:
        for (b = 0; b < a; b++)
        {
            for (c = a; c > b; c--)
            {
                printf("*");
            }
            printf("\n");
        }
        break;

    default:

        printf("you enterd wrong input");

        break;
    }

    return 0;
}
