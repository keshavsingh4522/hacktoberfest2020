// Hamiltonian Using DP 
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    vector<set<int>> edges(n);
    while(m--)
    {
        cin>>x>>y;
        edges[x].insert(y);
        edges[y].insert(x);
    }
    vector<vector<bool>> dp(n,vector<bool>((1<<n),false)); // Create a boolean array of n*2^n
    for(int i=0; i<n;i++)  
    dp[i][(1<<i)] = true; // Set bitmasks with only vertex to always true (Hamiltonian Path will Always Exist)

    // Now Iterate Over Boolean Array (i for mask and j for current vertex)
    for(int i = 0; i < (1<<n);i++)
        for(int j = 0; j < n;j++)
            if(i & (1<<j))  // Check whether ith mask contains jth vertex
                for(int k = 0; k < n;k++) 
                {
                    // Find a vertex k which is neighbour of vertex j and is in current subset
                    if(i & (1<<k) and edges[k].find(j) != edges[k].end() and j!= k and dp[k][i^(1<<j)])
                    dp[j][i] = true;
                }
            
    bool ans = false;
    // If last mask of any ith vertex contains true, a path will exist
    for(int i = 0;i<n;i++)
    {
        if(dp[i][(1<<n)-1])
        {
            ans = true;
            break;
        }
    }
    ans?cout<<"YES\n":cout<<"NO\n";

}
