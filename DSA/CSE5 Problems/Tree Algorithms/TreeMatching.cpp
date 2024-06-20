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
void dfs(int curr,int n,vector<list<int>> &adj,vector<bool> &included,vector<bool> &vis,int &count)
{
    vis[curr] = true;
    for(int elem : adj[curr])
    if(!vis[elem])
    dfs(elem, n , adj, included, vis,count);

    for(int elem : adj[curr])
    {
        if(!included[elem] and !included[curr])
        {
            included[elem] = true;
            included[curr] = true;
            count ++ ;
            break;
        }
    }
    
}
vector<list<int>> bfs(vector<list<int>>&adj ,int n)
{
    vector<list<int>> new_adj(n+1);
    vector<bool> vis(n+1,false);
    queue<int> temp;
    temp.push(1);
    vis[1] = true;
    while(!temp.empty())
    {
        int curr = temp.front();
        temp.pop();
        for(int elem : adj[curr])
        {
            if(!vis[elem])
            {
                vis[elem] = true;
                new_adj[curr].push_back(elem);
                temp.push(elem);
            }
        }
    }
    return new_adj;
}
 void solve()
 {
     int n, x, y;
     cin>>n;
     vector<list<int>> adj(n+1),new_adj;
     for(int i = 0; i < n-1;i++)
     {
         cin>>x>>y;
         adj[x].push_back(y);
         adj[y].push_back(x);
     }
     int count = 0;

     vector<bool> included(n+1,false),vis(n+1,false);
     new_adj = bfs(adj,n);
     dfs(1,n, new_adj, included,vis, count);
     cout<<count<<"\n";

 }

 int main()
 {
 ios_base::sync_with_stdio(false);
 cout.tie(NULL);
 cin.tie(NULL);
 solve();
 return 0;
 }
 