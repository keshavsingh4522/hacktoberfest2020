#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626
#define ll long long
#define lli long long int
#define fo(i,a,n) for(int i=a;i<n;i++)
#define pr(i,arr) for(auto i:arr)

typedef vector<int> vi;
typedef vector<ll> vl;
typedef map<ll,ll> ml;
typedef map<int,int> mi;

void file_i_p()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

ll fact(ll n) {
    ll res = 1;
    for(ll i=2;i<=n;i++) {
        res*=i;
    }
    return res;
}

ll _lcm(ll x,ll y) {
    return x*y/__gcd(x,y);
}

ll _gcd(ll a,ll b) {
    return a%b==0 ? b : _gcd(b,a%b);
}

bool isCheckCycle(int node,vector<int> adj[],vector<int> &vis,vector<int> &dfsVis)
{
    vis[node] = 1;
    dfsVis[node] = 1;

    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(isCheckCycle(it,adj,vis,dfsVis))
            {
                return true;
            }
        }
        else if(dfsVis[it])
        {
            return true;
        }
    }

    dfsVis[node] = 0;
    return false;
}

bool isCyclic(vector<int> adj[],int v)
{
    vector<int> vis(v+1,0);
    vector<int> dfsVis(v+1,0);
    for(int i=1;i<=v;i++)
    {
        if(!vis[i])
        {
            if(isCheckCycle(i,adj,vis,dfsVis))
            {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    int m,n;
    cin>>m>>n;
    vector<int> adj[m+1];
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    if(isCyclic(adj,m))
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }

}

int main() {
    
    file_i_p();

    solve();

    return 0;
}
