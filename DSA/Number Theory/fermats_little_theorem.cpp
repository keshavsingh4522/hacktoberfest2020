 
#include <bits/stdc++.h>
#define ll long long int
// Compute (A^B)%mod
using namespace std;
ll power(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll ans = power(a, b / 2, mod);
    ans %= mod;
    ans = (ans * ans) % mod;
    if ((b & 1) == 1)
        return (ans * a) % mod;
    return ans % mod;
}
ll stoi(string a, ll mod)
{
    ll ans = 0;
    for (size_t i = 0; i < a.length(); i++)
        ans = ((ans * 10) % mod + a[i] - '0') % mod;
    return ans;
}
int main()
{
    ll n, m, mod = 1000000007;
    ll t;
    cin >> t;
    string a, b;
    while (t--)
    {
        cin >> a >> b;
        n = stoi(a, mod);
        m = stoi(b, mod - 1); // using fermats little theorem
        cout << power(n, m, mod) << endl;
    }
    return 0;
}
