#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indset;
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define ll long long
#define mod 1000000007
#define inf 1ll << 62

ll power(ll x, ll y, ll modd)
{
    if (y == 0)
    {
        return 1;
    }
    else if (y == 1)
    {
        return (x % modd);
    }
    ll z = power(x % modd, y / 2, modd) % modd;
    if ((y % modd) % 2)
    {
        return (((((z % modd) * (x % modd)) % modd) * (z % modd)) % modd);
    }
    else
    {
        return (((z % modd) * (z % modd)) % modd);
    }
}
void sor(vector<ll> &x)
{

    sort(x.begin(), x.end());
}

void rev(vector<ll> &x)
{
    reverse(x.begin(), x.end());
}

ll gcd(ll x, ll y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

ll max(ll x, ll y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

ll min(ll x, ll y)
{
    if (x > y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

ll lcm(ll x, ll y)
{
    return x * y / gcd(x, y);
}

ll fact(ll n)
{
    ll res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

unsigned long long power(unsigned long long x,
                         int y, int p)
{
    unsigned long long res = 1;

    x = x % p;

    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

unsigned long long modInverse(unsigned long long n,
                              int p)
{
    return power(n, p - 2, p);
}
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
// vector<ll> a(200001);
// ll n, q, aa, b;
// vector<ll> seg(800001);

// void build(ll index, ll low, ll high)
// {
//     if (low == high)
//     {
//         seg[index] = a[low];
//         return;
//     }
//     ll mid = (low + high) / 2;
//     build(2 * index + 1, low, mid);
//     build(2 * index + 2, mid + 1, high);
//     seg[index] = (seg[2 * index + 1] + seg[2 * index + 2]);
// }

// ll query(ll index, ll low, ll high, ll l, ll r)
// {
//     if (low >= l && high <= r)
//     {
//         return seg[index];
//     }
//     if (high < l || low > r)
//     {
//         return 0;
//     }
//     ll mid = (low + high) / 2;
//     ll left = query(2 * index + 1, low, mid, l, r);
//     ll right = query(2 * index + 2, mid + 1, high, l, r);
//     return left + right;
// }

// vector<ll> prime;
// ll s = 0, sum = 0;
// ll maxx = 1000001;
// vector<bool> p(maxx + 1, 1);
// vector<ll> pp;
// void SieveOfEratosthenes()
// {
//     p[1] = 0, p[0] = 0;
//     for (ll i = 2; i * i <= maxx; i++)
//     {
//         if (p[i] == 1)
//         {
//             for (ll j = i * i; j <= maxx; j += i)
//             {
//                 p[j] = 0;
//             }
//         }
//     }
//     for (ll i = 0; i < maxx; i++)
//     {
//         if (p[i] == 1)
//         {
//             s++;
//         }
//         prime.push_back(s);
//     }
//     for (int i = 0; i <= maxx; i++)
//     {
//         if (p[prime[i]] == 1)
//         {
//             sum++;
//         }
//         pp.push_back(sum);
//     }
// }

// ll maxx = 50001;
// ll vis[50001];
// vector<ll> prime;
// void Seive()
// {
//     vis[0] = 1;
//     vis[1] = 1;
//     for (ll i = 2; i * i <= 2147483647; i++)
//     {
//         if (vis[i] == 0)
//         {
//             for (ll j = i * i; j * j <= 2147483647; j += i)
//             {
//                 vis[j] = 1;
//             }
//         }
//     }
//     for (ll i = 2; i * i <= 2147483647; i++)
//     {
//         if (vis[i] == 0)
//         {
//             prime.push_back(i);
//         }
//     }
// }

// ll Euclidean_gcd(ll a, ll b, ll &x, ll &y)
// {
//     if (b == 0)
//     {
//         x = 1, y = 0;
//         return a;
//     }
//     ll x1, y1;
//     ll d = Euclidean_gcd(b, a % b, x1, y1);
//     x = y1;
//     y = x1 - y1 * (a / b);
//     return d;
// }

//Segment Tree

vector<ll> a(200001);
vector<ll> tre(888888, INT64_MAX);

ll construct(ll ss, ll se, ll si)
{
    if (ss == se)
    {
        tre[si] = a[ss];
        return a[ss];
    }
    ll mid = (ss + se) / 2;
    tre[si] = min(construct(ss, mid, 2 * si + 1), construct(mid + 1, se, 2 * si + 2));
    return tre[si];
}

ll query(ll qs, ll qe, ll ss, ll se, ll si)
{
    if (qs > se || qe < ss)
    {
        return INT64_MAX;
    }
    if (qs <= ss && qe >= se)
    {
        return tre[si];
    }
    ll mid = (ss + se) / 2;
    return min(query(qs, min(qe, mid), ss, mid, 2 * si + 1), query(max(mid + 1, qs), qe, mid + 1, se, 2 * si + 2));
}

void update(ll ss, ll se, ll si, ll diff, ll i)
{
    if (se == ss)
    {
        tre[si] = diff;
    }
    else
    {
        ll mid = (ss + se) / 2;
        if (i <= mid)
            update(ss, mid, 2 * si + 1, diff, i);
        else
            update(mid + 1, se, 2 * si + 2, diff, i);

        tre[si] = min(tre[2 * si + 1], tre[2 * si + 2]);
    }
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    fo(i, n)
    {
        cin >> a[i];
    }
    construct(0, n - 1, 0);
    while (q--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        if (x == 1)
        {
            y--;
            update(0, n - 1, 0, z, y);
        }
        else
        {
            y--;
            z--;
            cout << query(y, z, 0, n - 1, 0) << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // freopen("A.TXT", "r", stdin);
    //freopen("A.OUT", "w", stdout);
    //freopen("INPUT.TXT", "r", stdin);
    //freopen("OUTPUT.TXT", "w", stdout);
    //SieveOfEratosthenes();
    ll t = 1;
    //Seive();
    //cin >> t;
    fo(tt, t)
    {
        solve();
    }
    return 0;
}
/*
https://codeforces.com/contest/839/problem/C
https://codeforces.com/contest/1253/problem/C
https://codeforces.com/problemset/problem/598/D
ll n, q;
vector<ll> a(200001);
vector<ll> tre(800004, 0);

ll construct(ll ss, ll se, ll si)
{
    if (ss == se)
    {
        tre[si] = a[ss];
        return a[ss];
    }
    ll mid = (ss + se) / 2;
    return tre[si] = construct(ss, mid, 2 * si + 1) + construct(mid + 1, se, 2 * si + 2);
}

ll query(ll qs, ll qe, ll ss, ll se, ll si)
{
    if (qs > se || qe < ss)
    {
        return 0;
    }
    else if (qs <= ss && qe >= se)
    {
        return tre[si];
    }
    ll mid = (ss + se) / 2;
    return query(qs, qe, ss, mid, 2 * si + 1) + query(qs, qe, mid + 1, se, 2 * si + 2);
}

void update(ll ss, ll se, ll i, ll si, ll diff)
{
    if (i < ss || i > se)
    {
        return;
    }
    tre[si] = tre[si] + diff;
    if (se > ss)
    {
        ll mid = (ss + se) / 2;
        update(ss, mid, i, 2 * si + 1, diff);
        update(mid + 1, se, i, 2 * si + 2, diff);
    }
}




// ll dp[1000001];
// ll inv[1000001];

// void init(string s)
// {
//     ll p = 31;
//     ll p_pow = 1;
//     dp[0] = (s[0] - 'a' + 1);
//     inv[0] = 1;
//     for (int i = 1; i < s.size(); i++)
//     {
//         ll ch = s[i] - 'a' + 1;
//         p_pow = (p_pow * p) % mod;
//         inv[i] = power(p_pow, mod - 2, mod);
//         dp[i] = (dp[i - 1] + (ch * p_pow)) % mod;
//     }
// }

// ll Hash(string s)
// {
//     ll p = 31;
//     ll p_pow = 1;
//     ll ans = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         ll ch = s[i] - 'a' + 1;
//         ans = (ans + ch * (p_pow)) % mod;
//         p_pow = (p_pow * p) % mod;
//     }
//     return ans;
// }

// ll stringHash(ll l, ll r)
// {
//     ll ans = dp[r];
//     if (l > 0)
//     {
//         ans -= dp[l - 1];
//         ans += mod;
//     }
//     ans = (ans * inv[l]) % mod;
//     return ans;
// }


*/
