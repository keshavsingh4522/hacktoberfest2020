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
vector<vector<int>> data(1001,vector<int>(100001,0));
void solve()
{
    // 0-1 Knapsack Problem
    int n, capacity;
    cin>>n>>capacity;
    vector<pair<int,int>> wtandp(n);
    for(auto &elem: wtandp)
    cin>>elem.first;
    for(auto &elem : wtandp)
    cin>>elem.second;

    for(int i = 1; i <= n;i ++)
    for(int j = 1; j <= capacity ; j ++)
    {
        if(wtandp[i-1].first <= j)
        data[i][j] = max(data[i-1][j],wtandp[i-1].second + data[i-1][j-wtandp[i-1].first]);
        else
        data[i][j] = data[i-1][j];
    }
    cout<<data[n][capacity];


    

}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
