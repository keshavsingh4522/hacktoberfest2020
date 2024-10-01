#include<bits/stdc++.h>
using namespace std;
int adj[1001][1001];
int main()
{
    int n,m;
    cout<<"Enter number of nodes";
    cin>>n;
    cout<<"Enter number of edges";
    cin>>m;
    adj[n+1][n+1];
    for(int i=0;i<m;i++)
    {
            int u,v;
            cin>>u>>v;
            adj[u][v]=1;
            adj[v][u]=1;
    }

      for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<adj[i][j]<<" ";
         cout<<endl;
    }
}
