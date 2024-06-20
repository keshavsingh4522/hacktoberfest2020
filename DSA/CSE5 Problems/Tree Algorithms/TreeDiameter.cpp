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
vector<int>find_depth(vector<list<int>> &edges,vector<int>&parent,int n)
{
    queue<int> temp;
    vector<int> depth(n+1);
    vector<bool> vis(n+1,false);
    depth[1] = 0;
    vis[1] = true;
    parent[1] = -1;
    temp.push(1);
    while(!temp.empty())
    {
        int curr = temp.front();
        temp.pop();
        for(int elem : edges[curr])
        {
            if(!vis[elem])
            {
                depth[elem] = depth[curr] + 1;
                parent[elem] = curr;
                vis[elem] = true;
                temp.push(elem);
            }

        }

    }
    return depth;
    
}
int findlca(int a1, int b1, vector<int> depth, vector<int> parent)
{
    int a = a1, b = b1;
    if(depth[a] < depth[b]) 
    swap(a,b);

    while(depth[a] != depth[b])
    a = parent[a];
 
    while(a != b)
    {
        a = parent[a];
        b = parent[b];
       
    }
      
    return a;
}
void solve()
{
    int n ,x,y;
    cin>>n;
    vector<list<int>> adj(n+1);
    vector<int> parent(n+1);
    for(int i = 0; i< n-1; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<pair<int,int>> ans;


    vector<int> depth = find_depth(adj,parent,n);
    for(int i = 1; i <= n ; i ++)
    if(adj[i].size() == 1)
    ans.push_back({depth[i],i});
    sort(ans.begin(),ans.end(),greater<pair<int,int>>());
  
    if(ans.size() == 1)
    cout<<ans[0].first;
    else
    {
       
        int h1 = ans[0].first,check = ans[0].second;
        for(int i = 1; i < ans.size(); i ++)
        if(findlca(check, ans[i].second, depth, parent) == 1)
        {
            // cout<<check<<" "<<ans[i].second<<"\n";
            cout<<h1 + ans[i].first<<" ";
            break;
        }
    }
    // cout<<ans[0] + ans[1];
}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
