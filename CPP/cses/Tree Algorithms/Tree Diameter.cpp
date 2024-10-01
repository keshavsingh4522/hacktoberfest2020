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

ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

ll nCrModp(ll n, ll r)
{
    if (r > n - r)
        r = n - r;

    ll C[r + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j - 1]) % mod;
    }
    return C[r];
}

vector<ll> a[200001];
ll vis[200001];
ll dis[200001];

void dfs(ll index, ll d)
{
    vis[index] = 1;
    dis[index] = d;
    for (auto child : a[index])
    {
        if (vis[child] == 0)
        {
            dfs(child, d + 1);
        }
    }
}

ll vis2[200001];
ll dis2[200001];

void dfs2(ll index, ll d)
{
    vis2[index] = 1;
    dis2[index] = d;
    for (auto child : a[index])
    {
        if (vis2[child] == 0)
        {
            dfs2(child, d + 1);
        }
    }
}

void solve(ll tt)
{
    ll n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll q, w;
        cin >> q >> w;
        a[w].push_back(q);
        a[q].push_back(w);
    }
    dfs(1, 0);
    ll node = -1, dd = INT64_MIN;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > dd)
        {
            node = i;
            dd = dis[i];
        }
    }
    dfs2(node, 0);
    dd = INT64_MIN;
    for (int i = 1; i <= n; i++)
    {
        dd = max(dd, dis2[i]);
    }
    cout << dd;
    //cout << "Case #" << tt << ": " << ans % mod << endl;
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
    //cin >> t;
    fo(tt, t)
    {
        solve(tt + 1);
    }
    return 0;
}
