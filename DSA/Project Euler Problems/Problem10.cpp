/* Summation of Primes */
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
bool check_prime(int n)
{
    if(n==2)
    return true;
    for(int i=2;i<=sqrt(n);i++)
    if(n%i==0)
    return false;
    return true;
}
int main()
{
    int below_number=2000000;
    ll sum=0;
    for(int i=2;i<below_number;i++)
    if(check_prime(i))
    sum+=i;
    cout<<sum;
    return 0;
}