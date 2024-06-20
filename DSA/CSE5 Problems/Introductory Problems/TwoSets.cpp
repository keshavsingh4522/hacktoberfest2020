#include<bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
const unsigned int M = 1000000007;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> tree;
void solve()
{
    ll n;
    cin>>n;
    ll check = n*(n+1)/2;
    if(check%2 != 0)
    cout<<"NO\n";
    else{
        set<int> a, b;
        for(int i =1; i <= n ; i ++)
        a.insert(i);

        check/=2;
        for(int i = n; i >= 1; i --)
        {
            if(check - i >= 0)
            {
                b.insert(i);
                check -= i ;
                a.erase(i);
            }
            if(check == 0)
            break;
        }
        cout<<"YES\n";
        cout<<a.size()<<"\n";
        for(int elem : a)
        cout<<elem<<" ";
        cout<<"\n"<<b.size()<<"\n";
        for(int elem : b)
        cout<<elem<<" ";

    }
}
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
solve();
return 0;
}
