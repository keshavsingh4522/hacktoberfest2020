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
{   int n ,temp=0,ans= 0;
    cin>>n;
    vector<pair<int,int>> data(n);
    vector<pair<int,char>> final_ans;
    for(auto &elem : data){
        cin>>elem.first>>elem.second;
        final_ans.push_back({elem.first,'X'});
        final_ans.push_back({elem.second,'Y'});
    }
    sort(final_ans.begin(),final_ans.end());
    for(auto elem : final_ans)
    {
        if(elem.second == 'X')
        temp ++ ;
        else
        temp --;
        ans = max(temp,ans);
    }
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
