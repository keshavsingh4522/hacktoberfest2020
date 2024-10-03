#include<stdio.h>
#include<stdbool.h>

bool isPalindrome(int a)
{
    if (a < 0) return false; // Negative numbers are not palindromes

    int backup = a, rev = 0;

    while (a != 0)
    {
        rev = (rev * 10) + (a % 10);
        a /= 10;
    }

    return rev == backup;
}

int main()
{
    int n = 122;

    if (isPalindrome(n))
        printf("%d is a Palindrome Number\n", n);
    else
        printf("%d is not a Palindrome Number\n", n);

    return 0;
}
