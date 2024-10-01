#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int> >
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define u_map unordered_map   
#define vcIT vector<int>::iterator 


bool isCycle(int index,vector<vector<int>> adj,vector<bool>& arr,int parent)
{
    arr[index]=true;
    for(auto x:adj[index])
    {
        if(x!=parent)
        {
            if(arr[x]==true) return true;
            if(arr[x]==false&&isCycle(x,adj,arr,index)) return true;
        }
    }

    return false;
}



void find_cycle(int n,vector<vector<int>> adj)
{
    bool cycle=false;
    vector<bool> arr(n+1,false);  //visited array

    for(int i=1;i<=n;i++)
    {
        if(!arr[i]&&isCycle(i,adj,arr,-1))
        cycle=true;
    }

    if(cycle) cout<<"cycle is present";
    else cout<<"cycle is not present";
}

int main()
{
    int n,m; 
    cout<<"Number of Nodes = ";
    cin>>n;
    cout<<"Number of Edges = ";
    cin>>m;
    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++)
    {
        int r,t;
        cin>>r>>t;
        adj[r].push_back(t);
        adj[t].push_back(r);
    }

    find_cycle(n,adj);
}