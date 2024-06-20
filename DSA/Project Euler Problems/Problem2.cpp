/* Even Fibonacci numbers */
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
    ll first_term=1,second_term=1,next_term,even_term_sum=0,n=4000000;
    while(1)
    {
        next_term=first_term+second_term;
        if(next_term>n)
        break;
        first_term=second_term;
        second_term=next_term;
        if(next_term%2==0)
        even_term_sum+=next_term;
    }
    cout<<even_term_sum;
    return 0;
}