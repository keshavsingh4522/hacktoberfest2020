//left most bit is called the least significant bit
//right most bit is called the most significant bit
//if a bit is set means it is equal to 1
//if a bit unset then it is equal to unset
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define asc(i,x,n) for(I i=x;i<n;i++)
#define dsc(i,x,n) for(I i=x;i>=n;i--)
#define W(t) int t;cin>>t;while(t--)
#define U unsigned
#define I long long int
#define S string
#define C char
#define D long double
#define A auto
#define B bool
#define pb push_back
#define V(x) vector<x>
#define mod 1000000007
void printbinary(int num)
{
    for(int i=10;i>=0;--i)
    {
             cout<<((num>>i)&1);
    }
    cout<<endl;
}
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  printbinary(9);
return 0;
}