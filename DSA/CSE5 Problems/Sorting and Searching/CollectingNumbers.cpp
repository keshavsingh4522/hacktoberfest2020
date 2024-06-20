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
    ll n,ans = 0 ;
    cin>>n;
    vector<ll> x(n);
    set<ll> data;
    for(ll &elem : x)
    cin>>elem;
    for(ll elem : x){
        if(data.find(elem-1) == data.end())
            ans ++ ;
        data.insert(elem);   
        
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
