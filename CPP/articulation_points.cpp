#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define fo(i,a,b) for(int i=a ; i<b ; i++)
#define foe(i,a,b) for(int i=a ; i<=b ; i++)
#define endl '\n'
#define ff first
#define ss second
#define MOD 1000000007
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited,point;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                point.push_back(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
       point.push_back(v);
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    // cin>>t;
    // t=1;
    while(t--)
    {
        
    }
    
    return 0;
}


