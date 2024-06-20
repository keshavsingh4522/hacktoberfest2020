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

int main()
{
    int n = 122;

    if(isPalindrome(n))
    printf("%d is a Palindrome Number",n);
    else
    printf("%d is not a Palindrome Number",n);

    return 0;

}


//Second Method

#include<stdio.h>
int main(){
int n,r,sum=0;
printf("to check palindrome number , enter a number ");
scanf("%d",&n);
while(n>0){
r=n%10;
sum=sum*10+r; 
n=n/10;
}
if(n==sum)
printf("it's palindrome number ",sum);
else
printf("it is not a palindrome number ");

return 0;
