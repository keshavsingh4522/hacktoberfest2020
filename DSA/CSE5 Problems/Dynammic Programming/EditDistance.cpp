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
vector<vector<int>> dp(5001,vector<int>(5001,-1));
int mini(int a, int b , int c){
    return min(min(a,b),c);
}
int editDist(string &s1, string &s2, int n, int m){
    if(m == 0)
    return n;
    else if(n == 0)
    return m;
    
    if(dp[n-1][m-1] != -1)
    return dp[n-1][m-1];
    
    if(s1[n-1] == s2[m-1])
    return dp[n-1][m-1] = editDist(s1, s2, n-1, m-1);

    int op1 = editDist(s1, s2, n, m-1);
    int op2 = editDist(s1, s2, n-1, m);
    int op3 = editDist(s1, s2, n-1, m-1);

    return dp[n-1][m-1] = 1 + mini(op1,op2,op3);
}
void solve()
{
    string a, b;
    cin>>a>>b;
    cout<<editDist(a,b, int(a.size()), int(b.size()));
}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
