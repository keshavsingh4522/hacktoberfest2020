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
set<int> findDigits(int elem)
{
    set<int> ans;
    while(elem!= 0)
    {
        if(elem%10!=0)
        ans.insert(elem%10);
         elem/=10;
    }
    return ans;
}
void solve()
{
    int n;
    cin>>n;
    vector<int> x(n+1,0);
    for(int i = 1; i <= 9;i ++)
    x[i] = 1;
    for(int i = 10;i <= n ; i ++)
    {
        int ans = INT_MAX;
        for(int elem : findDigits(i))
            ans = min(ans,1 + x[i-elem]);
        x[i] = ans;
    }
  cout<<x[n];

}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
