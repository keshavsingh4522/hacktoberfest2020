#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
const unsigned int M = 1000000007;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> tree;
void solve()
{
    ll n, x,ans = 0;
    cin>>n>>x;
    vector<ll> data(n);
    for(ll &elem : data)
    cin>>elem;
    sort(data.begin(),data.end(),greater<int>());
    ll curr = 0;
    int low = 0, high = n-1;
    while(low <= high)
    {
        if(data[low] + data[high] <= x)
        low ++, high --, ans ++;
        else if(data[low] + data[high] > x)
        low ++, ans ++;
    }
    cout<<ans<<"\n";
}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
