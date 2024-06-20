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
ll findPower(ll a, ll b)
{
    ll res = 1;
    while(b > 0)
    {
        if(b&1)
        res = (res*a)%M;
 
        a = (a*a) % M;
        b = b>>1; 
    }
    return res;
}
void solve()
{
    ll n , a, b;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        cout<<findPower(a,b)<<"\n";
    }

}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
