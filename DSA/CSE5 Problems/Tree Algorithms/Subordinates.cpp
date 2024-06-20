#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
const unsigned int M = 1000000007;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> tree;
void dfs(int curr,int n,vector<list<int>> &adj,vector<int> &ans,vector<bool> &vis)
{
    vis[curr] = true;
    for(int elem : adj[curr])
    if(!vis[elem])
    dfs(elem, n , adj, ans, vis);

    for(int elem : adj[curr])
    ans[curr] += ans[elem];
    ans[curr] += adj[curr].size();
    
}
void solve()
{
    int n ,temp;
    cin>>n;
    vector<list<int>> adj(n+1);
    for(int i = 2; i <= n ; i++)
    {
        cin>>temp;
        adj[temp].push_back(i);
     
    }
       vector<bool> vis(n+1,false);
        vector<int> ans(n+1,0);

    dfs(1, n, adj, ans,vis);
    for(int i = 1;i <= n ; i++)
    cout<<ans[i]<<" ";
}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
