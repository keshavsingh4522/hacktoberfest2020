/* Largest Palindrome Product */
#include<bits/stdc++.h>
using namespace std;
bool check_palindrome(int n)
{
   int temp=n,rev=0;
   while(temp)
   {
       rev=rev*10+temp%10;
       temp/=10;
   }
   if(rev==n)
   return true;
   else
   return false;
}
int main()
{
    int no_of_digits=3,largest_palindrome=-1;
    for(int i=pow(10,no_of_digits-1);i<pow(10,no_of_digits);i++)
    {
        for(int j=pow(10,no_of_digits-1);j<pow(10,no_of_digits);j++)
        if(check_palindrome(i*j))
        largest_palindrome=max(largest_palindrome,i*j);
    
    }
    cout<<largest_palindrome;
    return 0;
}