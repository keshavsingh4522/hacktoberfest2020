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
    int n,m,x,ans = 0;
    cin>>n>>m>>x;
    vector<int> people(n);
    vector<int> appartment(m);
    vector<bool> assigned(m,false);
    for(int&elem : people)
    cin>>elem;
    for(int&elem: appartment)
    cin>>elem;
    sort(people.begin(),people.end());
    sort(appartment.begin(),appartment.end());
    int i = 0,j = 0;
    while(i < n and j < m)
    {
        if(abs(people[i]-appartment[j]) <= x)
        {
            i ++ , j ++;
            ans ++;
        }
        else{
            if(people[i] - appartment[j] > x)
            j++;
            else
             i++;
        }

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
