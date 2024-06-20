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
    int n , m,ans = 0;
    cin>>n>>m;
    vector<int> x(n+1,0);
    vector<vector<int>> dp(n+2,vector<int>(m+2,0));
    for(int i = 1; i <= n ; i ++)
    cin>>x[i];
    for(int i = 1; i <= n ; i ++){

        for(int j = 1; j <= m ; j ++){
            
      if(i == 1){
            if(x[i] == 0 or x[i] ==j) dp[i][j] = 1;
            else dp[i][j] =0;
      }else{
          if(x[i] == 0 or x[i] == j)
          dp[i][j] = (dp[i-1][j-1]%M + dp[i-1][j]%M + dp[i-1][j+1]%M)%M;
          else dp[i][j] = 0;
      }
        }
    }
    for(int j = 1; j <= m ; j ++)
    ans = (ans%M + dp[n][j]%M)%M;
    cout<<ans<<"\n";
}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
