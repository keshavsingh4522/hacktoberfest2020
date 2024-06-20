/* 10001st Prime */
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
bool check_prime(ll n)
{  
   if(n==2)
   return true;
   for(int i=2;i<=sqrt(n);i++)
   if(n%i==0)
   return false;
   return true;
}
int main()
{   ll current_no=2;
    int nth_prime=10001,index=0;
    while(1)
    {
        if(check_prime(current_no))
        index++;
        if(index==nth_prime)
        break;
        current_no++;
    }
    cout<<current_no;
    return 0;

}