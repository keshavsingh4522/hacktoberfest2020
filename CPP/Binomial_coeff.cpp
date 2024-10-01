#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int F[1000001];

void pre_calculation()
{
    long long int i;
    F[0] = 1;
    F[1] = 1;
    for (i = 2; i <= 1000000; i++)
    {
        F[i] = (F[i - 1] * i) % mod;
    }
}

long long int inv(long long int f, long long int power)
{
    long long int res = 1;

    while (power)
    {
        if (power % 2)
        {
            res = (res * f) % mod;
            power--;
        }
        else
        {
            f = (f * f) % mod;
            power /= 2;
        }
    }

    return res;
}

long long int nCr(long long int n, long long int r)
{
    if (r > n)
        return 0;

    long long int res = F[n];

    res = res * inv(F[r], mod - 2) % mod;
    res = res * inv(F[n - r], mod - 2) % mod;

    return res;
}

int main()
{
    pre_calculation();
    long long int test_cases;
    cout << "enter the no of test cases" << endl;
    cin >> test_cases;
    long long int n, r;
    while (test_cases--)
    {
        cout << "enter the n and r" << endl;
        cin >> n >> r;
        cout << nCr(n, r) << endl;
    }
    return 0;
}