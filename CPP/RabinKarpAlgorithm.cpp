#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long int

int check_match(string S, string Pattern, int i)
{
    for (int j = 0; j < Pattern.size(); j++)
    {
        if (S[i++] != Pattern[j])
        {
            return 0;
        }
    }
    return 1;
}

int rabinKarp(string S, string Pattern)
{
    int d = 256;
    int n = S.size();
    int m = Pattern.size();
    if (n < m)
    {
        return -1;
    }
    int pat_hash = 0;
    int s_hash = 0;
    int multiplier = 1;

    for (int i = 0; i < m; i++)
    {
        pat_hash = (pat_hash * d + Pattern[i]) % mod;
        s_hash = (s_hash * d + S[i]) % mod;
        if (i != m - 1)
            multiplier = (multiplier * d) % mod;
    }
    for (int i = 0; i <= n - m; i++)
    {
        if (s_hash == pat_hash)
        {
            if (check_match(S, Pattern, i))
            {
                return i;
            }
        }
        if (i < n - m)
        {
            s_hash = ((s_hash - S[i] * multiplier) * d + S[i + m]) % mod;
            if (s_hash < 0)
            {
                s_hash += mod;
            }
        }
    }
    return -1;
}

signed main()
{
    string S;
    getline(cin, S);
    string pattern;
    cin >> pattern;
    cout << rabinKarp(S, pattern);
}
