#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPalindrome(int a)
{
    int backup = a,rev = 0;

    while(a)
    {
        rev = (rev*10) + (a%10);
        a/=10;
    }

    return rev == backup;
}

int main()
{
    int n = 122;

    if(isPalindrome(n))
    printf("%d is a Palindrome Number",n);
    else
    printf("%d is not a Palindrome Number",n);

    return 0;

}
