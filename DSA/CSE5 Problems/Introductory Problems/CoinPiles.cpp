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
    int t;
    ll a, b,x,y;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        x = -1,y = -1;
        if((2*b - a)%3 == 0)
        y = (2*b - a)/3;
        if((a-y)%2 == 0)
        x = (a - y)/2;
        if(x >= 0 and y>= 0)
        cout<<"YES\n";
        else 
        cout<<"NO\n";
        
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
