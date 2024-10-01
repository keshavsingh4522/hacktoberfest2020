#include<stdio.h>
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

int main(void)      //Execution of each program start from main() function.
{
    int n = 122;

    if(isPalindrome(n))
    printf("%d is a Palindrome Number",n);
    else
    printf("%d is not a Palindrome Number",n);

    return 0;

}
