//TITLE: master.cpp
//AUTHOR: N Harsha Vardhan
//DATE: 2021-09-23
//TIME: 01:00:09
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define mp make_pair
#define pb push_back
#define S second
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FO(x) for (int i = 0; i < x; i++)
#define ROF(x) for (int i = x; i >= 0; i--)
#define sz(a) (ll)(a.size())
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7;
const ll INF = 1e18;

//returns a^b%m
//if really big numbers , python might be the better choice
long long binpow(long long a, long long b, long long m)
{
    a %= m; //if a is really big, this is needed
    long long res = 1; //initialize result as 1
    while (b > 0) //while b is greater than 0
    {
        if (b & 1)  //if b is odd
            res = res * a % m; //multiply result with a
        a = a * a % m; //square a
        b >>= 1; //divide b by 2
    }
    return res; //return result
}

//gets modular inverses ax=1modm
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
        int res = (x % m + m) % m;
        return res;
    }
}
vi modularInverseTillN(int n, int prime)
{
    vi dp(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[prime % i] *
                (prime - prime / i) % prime;

    return dp;
}


//easy implementation of seive of erathosthenes
vector<bool> seiveeasy(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

//this returns the power of k in n!
//works only when k is prime....if k is composite then the calculate the same value for the largest divisor of k.
int fact_pow(int n, int k)
{
    int res = 0;
    while (n)
    {
        n /= k;
        res += n;
    }
    return res;
}
//worst case works in n/2 ops.
//iterative method better than recursive.
ll ncr(ll n, ll r)
{
    if(r>n/2)
    {
        r=n-r;
    }
    if (r > n)
        return 0;
    if (r == 0)
        return 1;
    ll ans = 1;
    for (ll i = 1; i <= r; i++)
        ans = (ans * (n - i + 1)) / i;
    return ans;
}
//npr=ncr*r!
ll npr(ll n, ll r)
{
    int ans=1;
    for(int i=n;i>n-r;i--)
    {
        ans*=i;
    }
    return ans;
}
// a function to return a vector which provides with all factorials from 1 to n
vector <ll> fact(ll n,ll mod)
{
    vector <ll> factorials;
    factorials.pb(1);
    for (ll i = 1; i <= n; i++)
    {
        factorials.pb((factorials[i - 1] * i)%mod);
    }
    return factorials;
}

//works in sqrt(n) time
int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
//works in O(nloglog(n)) time and returns the phi from 1 to n
vi phi_1_to_n(int n)
{
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    return phi;
}

// ax + by = __gcd(a, b)
// returns __gcd(a, b)
__int128 extended_euclid(__int128 a, __int128 b, __int128 &x, __int128 &y)
{
    __int128 xx = y = 0;
    __int128 yy = x = 1;
    while (b)
    {
        __int128 q = a / b;
        __int128 t = b;
        b = a % b;
        a = t;
        t = xx;
        xx = x - q * xx;
        x = t;
        t = yy;
        yy = y - q * yy;
        y = t;
    }
    return a;
}
// finds x such that x % m1 = a1, x % m2 = a2. m1 and m2 may not be coprime
// here, x is unique modulo m = lcm(m1, m2). returns (x, m). on failure, m = -1.
pair<__int128, __int128> CRT(__int128 a1, __int128 m1, __int128 a2, __int128 m2)
{
    __int128 p, q;
    __int128 g = extended_euclid(m1, m2, p, q);
    if (a1 % g != a2 % g)
        return make_pair(0, -1);
    __int128 m = m1 / g * m2;
    p = (p % m + m) % m;
    q = (q % m + m) % m;
    return make_pair((p * a2 % m * (m1 / g) % m + q * a1 % m * (m2 / g) % m) % m, m);
}
int main()
{
    /*for fastness*/
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*if input file is given and output file needs to be generated
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */
}
