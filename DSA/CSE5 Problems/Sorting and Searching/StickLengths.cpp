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
ll cost(vector<ll> data, ll el){
    ll cost = 0;
    for(ll elem : data)
    cost += abs(elem - el);
    return cost;
}
void solve()
{
    ll cost1=0, n,mini= LLONG_MAX,maxi = LLONG_MIN;
    cin>>n;
    vector<ll> ans(n);
 
    for(ll &elem : ans)
    {
        cin>>elem;
        mini = min(elem,mini);
        maxi = max(elem,maxi);
    }
    sort(ans.begin(),ans.end());
    while(mini <= maxi){
        ll mid = mini + (maxi-mini)/2;
        if(cost(ans,mid) <= cost(ans,mid-1) and cost(ans,mid) <= cost(ans,mid+1)){
            cost1 = cost(ans,mid);
            break;
        }
        else if(cost(ans,mid + 1) <= cost(ans,mid)){
            mini = mid + 1;
        }
        else if(cost(ans,mid -1) <= cost(ans,mid)){
            maxi = mid - 1;
        }
    }
    cout<<cost1<<"\n";

   
    
}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
