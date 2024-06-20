/* Largest Prime Factor */
#include<bits/stdc++.h>
#define ll long 
using namespace std;
int main()
{
   ll n=600851475143,largest_prime=-1;
        while(n%2==0)
        {
            n/=2;
            largest_prime=max(largest_prime,ll(2));
        }
        for(ll i=3;i<n;i=i+2)
        {
            while(n%i==0)
            {
               n/=i;
               largest_prime=max(largest_prime,i);
            }
        }
        cout<<max(largest_prime,n);
        return 0;
   
}