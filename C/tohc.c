#include <stdio.h>

// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, char A, char B,char C)
{
    if (n>1)
    {
        towerOfHanoi(n - 1, A,C,B);
        printf("\n Move disk from rod %c to rod %c",A,C);
        towerOfHanoi(n - 1,B,A,C);
    }
}

int main()
{
    int n ;
    printf("Enter the no. of discs: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
    return 0;
}
