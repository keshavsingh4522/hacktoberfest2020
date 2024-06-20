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
bool comparator(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;

}
void solve()
{   int n ,temp=0,ans= 0;
    cin>>n;
    vector<pair<int,int>> data(n);
    for(auto &elem : data){
        cin>>elem.first>>elem.second;
    }
    sort(data.begin(),data.end(),comparator);
    int i = 0,end = -1;
    while(i < n){
        if(data[i].first>= end){
            ans ++;
            end = data[i].second;
            i ++;
        }
        else i ++;
    } 
    cout<<ans;
}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
