#include <bits/stdc++.h>
#include <math.h>
#include <iterator>
#include <map>
#include <list>
#include <cmath>
#include <queue>
using namespace std;
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define ll long long
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

list<ll> a[5];
void bfs(int src)
{
    queue<int> q;
    bool *vis = new bool[5 + 1]{0};
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (int n : a[node])
        {
            if (!vis[n])
            {
                q.push(n);
                vis[n] = true;
            }
        }
    }
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

void primeFactors(ll n, vector<ll> &vec)
{

    while (n % 2 == 0)
    {
        vec.push_back(2);
        n = n / 2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            vec.push_back(i);
            n = n / i;
        }
    }

    if (n > 2)
        vec.push_back(n);
}

ll lcm(ll x, ll y)
{
    return x * y / gcd(x, y);
}

ll g(ll x)
{
    for (ll i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return i;
        }
    }
    return 0;
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

            else
                cnt = cnt + 2;
        }
    }
    return cnt;
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

    return 0;
}
int subArraylen(ll arr[], ll n, ll K)
{
    // Stores the frequency of
    // prefix sums in the array
    unordered_map<int, int> mp;

    mp[arr[0]] = 0;

    for (int i = 1; i < n; i++)
    {

        arr[i] = arr[i] + arr[i - 1];
        mp[arr[i]] = i;
    }

    // Initialize len as INT_MAX
    int len = INT_MAX;

    for (int i = 0; i < n; i++)
    {

        // If sum of array till i-th
        // index is less than K
        if (arr[i] < K)

            // No possible subarray
            // exists till i-th index
            continue;

        else
        {

            // Find the exceeded value
            int x = arr[i] - K;

            // If exceeded value is zero
            if (x == 0)
                len = min(len, i);

            if (mp.find(x) == mp.end())
                continue;
            else
            {
                len = min(len, i - mp[x]);
            }
        }
    }

    return len;
}

void solve()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> a;
    do
    {
        a.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << a.size() << endl;
    fo(i, a.size())
    {
        cout << a[i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}

//0 3 1 0 5 2 6
//0 0 1 2 3 5 6
/*
binary for a no just greater than that no:

ll start = 0, end = n - 1;
        ll c = 0;
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
        cout << c << endl;

        */