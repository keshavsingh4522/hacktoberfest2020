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
    int n, val;
    cin>>n>>val;
    vector<int>x(n),memo(val+1,0);
    for(int &elem : x)
        cin>>elem;

    memo[0] = 1;
    for(int coins : x)
    for(int i = 1; i <= val ; i ++)
    {   
        if(i - coins >= 0 )
        memo[i] = (memo[i]%M + memo[i-coins]%M)%M;
    }
 
   cout<<memo[val];
}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
