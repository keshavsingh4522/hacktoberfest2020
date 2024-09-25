#include<bits/stdc++.h>
using namespace std;
#define MAXN   200005
#define ll long long int
vector<int> spf(MAXN);

void sieve()
{
    spf[1] = 1;
    for (ll i=2; i<MAXN; i++)spf[i] = i;
    for (ll i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (ll i=3; i*i<MAXN; i++)
    {
        
        if (spf[i] == i)
        {
            
            for (ll j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
int main(){
  sieve();
}