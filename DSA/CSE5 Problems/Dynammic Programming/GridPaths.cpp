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
void solve()
{
     int n ;
     cin>>n;
     vector<vector<char>> grid(n+1,vector<char>(n+1));
     vector<vector<int>> ans(n+1,vector<int> (n+1,0));
     for(int i = 1; i <= n ; i ++)
     for(int j = 1; j <= n ; j ++)
     cin>>grid[i][j];
     for(int i = n;i >= 1; i --)
     for(int j = n; j >= 1; j --)
     {
         if(i == n and j == n and grid[n][n] != '*')
         ans[i][j] = 1;
         else if(grid[i][j] != '*'){
             if(i < n and grid[i+1][j] == '.' )
             ans[i][j] = (ans[i][j]%M + ans[i+1][j]%M)%M;
             if(j < n and grid[i][j+1]=='.')
             ans[i][j] = (ans[i][j]%M + ans[i][j+1]%M)%M;  
            
         }
     }
    cout<<ans[1][1];                             
}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
