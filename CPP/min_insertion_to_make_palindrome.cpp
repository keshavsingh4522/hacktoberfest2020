#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin >> s;
        ll n = s.length();
        int dp[n][n],l,h,len;
        memset(dp,0,sizeof(dp));
        for(len = 1;len < n;len++)
        {
            for(l=0,h=len; h<n;l++,h++)
            {
                if(s[l] == s[h])
                    dp[l][h] = dp[l+1][h-1];
                else
                    dp[l][h] = min(dp[l][h-1],dp[l+1][h]) + 1;
            }
        }
        // for(ll i=0;i<n;i++)
        // {
        //     for(ll j=0;j<n;j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << dp[0][n-1] << endl;
    }
    return 0;
}