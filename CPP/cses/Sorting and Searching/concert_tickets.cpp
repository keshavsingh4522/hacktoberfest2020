#include <bits/stdc++.h>
#include <math.h>
#include <iterator>
#include <map>
#include <stack>
#include <list>
#include <cmath>
#include <queue>
using namespace std;
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define ll long long
#define mod 1000000007
ll power(ll x, ll y)
{
    if (y == 0)
    {
        return 1;
    }
    else if (y == 1)
    {
        return x;
    }
    ll z = power(x, y / 2);
    if (y % 2)
    {
        return z * x * z;
    }
    else
    {
        return z * z;
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
*/
void solve()
{
    ll n, q;
    cin >> n >> q;
    multiset<ll> a;
    fo(i, n)
    {
        ll q1;
        cin >> q1;
        a.insert(q1);
    }
    while (q--)
    {
        ll w;
        cin >> w;
        auto x = a.upper_bound(w);
        if (x == a.begin())
        {
            cout << -1;
        }
        else
        {
            x--;
            cout << *x;
            a.erase(x);
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
#ifdef DEBUG
#define debug(...)                    \
    do                                \
    {                                 \
        fprintf(stderr, __VA_ARGS__); \
    } while (false)
#else
#define debug(...) \
    do             \
    {              \
    } while (false)
#endif

    // freopen("A.TXT", "r", stdin);
    //freopen("A.OUT", "w", stdout);
    //freopen("INPUT.TXT", "r", stdin);
    //freopen("OUTPUT.TXT", "w", stdout);
    //SieveOfEratosthenes(mxn);
    ll t = 1;
    // cin >> t;
    fo(tt, t)
    {
        solve();
    }
    return 0;
}

//1 2 1 3 2 7 4 2
//1 3 2 5 8 4 7 6
//1 1 2 2 2 3 4 7