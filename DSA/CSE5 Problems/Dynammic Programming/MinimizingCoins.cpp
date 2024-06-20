#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
const unsigned ll M = 1000000007;
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> tree;
void solve()
{
    ll n, sum;
    cin>>n>>sum;
    vector<ll> x(n),memo(sum+1,0);
    for(ll &elem : x)
    cin>>elem;

    for(ll i = 1; i <= sum ; i++){
        ll ans = INT_MAX;
        bool ans_found = false;
        for(ll coin : x)
        {
            if(i - coin >= 0 and memo[i-coin] != -1)
            ans = min(ans,1 + memo[i - coin]),ans_found = true;
        }
        if(!ans_found)
        memo[i] = -1;
        else
        memo[i] = ans;
    }

    cout<<memo[sum]<<"\n";
    
}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
