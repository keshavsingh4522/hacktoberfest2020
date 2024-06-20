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
    ll n,m,temp;
    cin>>n>>m;
    vector<ll> x(n);
    map<ll,set<ll>> data;
    for(ll i = 0 ; i < n ; i  ++ )
    {
        cin>>temp;
        data[temp].insert(i + 1);
    } 
    bool ans = false;
    for(auto elem : data){
        if(ans) break;
        if(elem.first != (m - elem.first) and data.find(m- elem.first) != data.end()){
            cout<<*elem.second.begin()<<" "<<*data[m-elem.first].begin()<<" ";
            break;
        }else if(data.find(m-elem.first) != data.end()){
            if(elem.second.size() >= 2)
            {
                cout<<*elem.second.begin()<<" "<<*elem.second.rbegin()<<"\n";
                ans = true;
                break;
            }
        }
    }
    if(!ans) cout<<"IMPOSSIBLE\n";
}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
