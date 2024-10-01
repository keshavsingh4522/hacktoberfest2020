#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

int maxn = (int)2e6 + 1; // max possible value of n
ll m = (ll)1e9 + 7; // the prime number under which the mod is taken      

vector<int> fact(maxn), inv(maxn), inv_fact(maxn);

// for each i from 0 to maxn, fact[i] represents i! % m
// for each i from 1 to maxn, inv[i] represents the modular inverse of i under m
// for each i from 0 to maxn, inv_fact[i] represents the modular inverse of i! under m

void preprocess()
{
    fact[0] = fact[1] = 1;
    inv[0] = inv[1] = 1;
    inv_fact[0] = inv_fact[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        fact[i] = (ll)fact[i - 1] * i % m;
        inv[i] = (ll)inv[m % i] * (m - m / i) % m;
        inv_fact[i] = (ll)inv_fact[i - 1] * inv[i] % m;
    }
    return;
}

int nCr(int n, int r)
{
    if (r > n)
        return 0;
    return ((ll)fact[n] * inv_fact[r] % m) * inv_fact[n - r] % m;
}

int main()
{
    preprocess();
    int n = 1000, r = 50;
    cout<<nCr(n, r)<<'\n';
    return 0;
}