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
class DisjointSet{
    public:
    vector<int> parent,rank;
    int nodes;
    DisjointSet(int n)
    {
        this->nodes = n;
        this->parent = vector<int>(n+1);
        this->rank = vector<int> (n+1,0);
        for(int i = 1; i <= n ; i++)
        parent[i] = i;
        
    }
    int findparent(int elem)
    {
        if(parent[elem] == elem)
        return elem ;
       return parent[elem] = findparent(parent[elem]);
    }
    void Union(int a, int b)
    {

        int para = findparent(a);
        int parb = findparent(b);
     if(rank[para] > rank[parb])
     parent[parb] = para,rank[para]++;
     else if(rank[parb] > rank[para])
     parent[para] = parb,rank[parb]++;
     else {
         rank[para] ++ ;
         parent[parb] = para;
     }
    }
};
void solve()
{
    int n, m,x,y,start,end;
    cin>>n>>m;
    DisjointSet d(n);
    vector<list<int>> adj(n+1);
    bool found = false;
    for(int i = 0; i < m ; i++)
    {
        cin>>x>>y;
      
        if(d.findparent(x) == d.findparent(y))
        start = x,end = y,found = true;
        else
        {d.Union(x, y);
        adj[x].push_back(y);
        adj[y].push_back(x);}
    }
    if(!found) {cout<<"IMPOSSIBLE\n"; return ;}
    queue<int> temp;
    vector<bool> vis(n+1,false);
    vector<int> parent(n+1,-1);
    vis[start] = true;
    temp.push(start);
    while(!temp.empty())
    {
        int curr = temp.front();
        temp.pop();
        for(int elem : adj[curr])
        {
            if(!vis[elem])
            {
                vis[elem] = true;
                temp.push(elem);
                parent[elem] = curr;
                
            }
        }
    }
    vector<int> path;
 int curr = end;
 while(curr != start)
 {
     path.push_back(curr);
     curr = parent[curr];

 }
 

 reverse(path.begin(),path.end());
 cout<<path.size() + 2<<"\n";
 cout<<start<<" ";
 for(int elem : path)
 cout<<elem<<" ";
 cout<<start<<" ";

    
  

}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
