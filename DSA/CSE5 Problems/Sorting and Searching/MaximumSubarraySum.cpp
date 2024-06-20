#include<bits/stdc++.h> 
#include <climits>
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
    int n; 
    cin>>n;
    vector<ll> x(n);
    for(ll &elem : x)
    cin>>elem;

    ll max_so_far = LLONG_MIN, max_ending_here =0;
    for(ll i = 0; i < n ; i ++ ){
        max_ending_here = max_ending_here + x[i];
        if(max_so_far < max_ending_here)
        max_so_far = max_ending_here;

        if(max_ending_here < 0)
        max_ending_here = 0;
    }
    cout<<max_so_far<<"\n";
    

}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
