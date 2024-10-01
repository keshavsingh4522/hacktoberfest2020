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

ll bina(vector<ll> a, ll n, ll m)
{
    ll start = 0, end = n - 1;
    ll c = 0;
    if (m >= a[n - 1])
    {
        return n;
    }
    while (start <= end)
    {
        ll mid = (start + end) / 2;
        if (m >= a[mid])
        {
            c = mid + 1;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return c;
}

ll binarySearch(vector<ll> arr, ll l, ll r, ll x)
{
    if (r >= l)
    {
        ll mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

ll prime(ll n)
{
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return i;
        }
    }
    return 0;
}

ll countBits(ll number)
{
    return (ll)log2(number) + 1;
}

ll countDivisors(ll n)
{
    ll cnt = 0;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                cnt++;

            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
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
/*
const ll mxn = (2 * 100000) + 1;
vector<ll> pr;
bool pri[mxn + 1];
vector<ll> no;
vector<ll> cop(10000001, 1);
void SieveOfEratosthenes(int n)
{

    memset(pri, true, sizeof(pri));
    pri[1] = false;
    pri[0] = false;
    fo(i, 10000001)
    {
        cop[i] = i;
    }
    for (int p = 2; p <= n; p++)
    {

        if (cop[p] == p)
        {
            //cop[p] = p - 1;
            for (int i = p; i <= n; i += p)
            {
                cop[i] *= (p - 1);
                cop[i] /= (p);
            }
        }
    }
}

vector<vector<ll>> expo(ll n, vector<vector<ll>> a, vector<vector<ll>> one)
{
    if (n <= 0)
    {
        return one;
    }
    else if (n == 1)
    {
        return a;
    }
    vector<vector<ll>> mat = expo(n / 2, a, one);
    if (n % 2)
    {
        vector<vector<ll>> ans2;
        fo(i, mat.size())
        {
            vector<ll> temp(mat.size(), 0);
            ans2.push_back(temp);
        }
        fo(i, mat.size())
        {

            fo(j, mat.size())
            {

                fo(k, mat.size())
                {
                    ans2[i][j] += mat[i][k] * a[k][j];
                    ans2[i][j] %= mod;
                }
                ans2[i][j] %= mod;
            }
        }
        vector<vector<ll>> ans3;
        fo(i, mat.size())
        {
            vector<ll> temp(mat.size(), 0);
            ans3.push_back(temp);
        }
        fo(i, mat.size())
        {

            fo(j, mat.size())
            {

                fo(k, mat.size())
                {
                    ans3[i][j] += ans2[i][k] * mat[k][j];
                    ans3[i][j] %= mod;
                }
                ans3[i][j] %= mod;
            }
        }
        return ans3;
    }
    else
    {
        vector<vector<ll>> ans2;
        fo(i, mat.size())
        {
            vector<ll> temp(mat.size(), 0);
            ans2.push_back(temp);
        }
        fo(i, mat.size())
        {
            fo(j, mat.size())
            {
                fo(k, mat.size())
                {
                    ans2[i][j] += mat[i][k] * mat[k][j];
                    ans2[i][j] %= mod;
                }
                ans2[i][j] %= mod;
            }
        }
        return ans2;
    }
}

vector<int> ninjaChess2021(string king, string ninja) {

}



ll v, source, graph[100][100];
vector<ll> dist(100, INT64_MAX);
ll vis[100];
ll parent[100];
void dijktras()
{
    fo(i, v)
    {
        parent[i] = i;
    }
    dist[0] = 0;
    fo(i, v)
    {
        ll mi = INT64_MAX;
        ll minnode = 0;
        fo(j, v)
        {
            if (!vis[j] && dist[j] < mi)
            {
                mi = dist[j];
                minnode = j;
            }
        }
        vis[minnode] = 1;
        fo(j, v)
        {
            if (graph[minnode][j] != INT64_MAX && dist[j] < dist[minnode] + graph[minnode][j])
            {
                dist[j] = dist[minnode] + graph[minnode][j];
                parent[j] = minnode;
            }
        }
    }
}

//vector<ll> a;
vector<ll> adj[1000001];
queue<ll> q;
vector<bool> used(1000001);
vector<int> d(1000001);
vector<ll> level(1000001);

void bfs(ll s)
{
    q.push(s);
    used[s] = true;
    d[s] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : adj[v])
        {
            if (!used[u])
            {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                level[d[u]]++;
                //cout << u << " ";
            }
        }
    }
}
void dfs(ll s, ll dd)
{
    used[s] = 1;
    d[s] = dd;
    for (auto child : adj[s])
    {
        if (used[child] == 0)
        {
            dfs(child, dd);
        }
    }
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void perm(char *s, ll l, ll r)
{
    if (l == r)
    {
        cout << s[l];
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s + l, s + i);
            perm(s, l + 1, r);
            swap(s + l, s + i);
            cout << endl;
        }
    }
}
*/
void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = power(b, c, mod - 1);
    cout << power(a, x, mod) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    // freopen("A.TXT", "r", stdin);
    //freopen("A.OUT", "w", stdout);
    //freopen("INPUT.TXT", "r", stdin);
    //freopen("OUTPUT.TXT", "w", stdout);
    //SieveOfEratosthenes(mxn);
    ll t = 1;
    cin >> t;
    fo(tt, t)
    {
        solve();
    }
    return 0;
}
