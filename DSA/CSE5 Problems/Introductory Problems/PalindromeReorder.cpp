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
    int count = 0;
    string s;
    cin>>s;
    map<char,int> data;
    for(char elem : s)
    data[elem] ++;
    for(auto elem : data)
    {
        if(elem.second%2 != 0)
        count ++ ;
    }
    if(count > 1)
    cout<<"NO SOLUTION\n";
    else{
        char ex='?';
        string a, b;
        for(auto &elem : data)
        {
            while(elem.second != 0)
            {
                if(elem.second == 1)
                ex = elem.first,elem.second--;
                else{
                    a += string(1,elem.first);
                    b += string(1,elem.first);
                    elem.second -=2;
                }
            }
        }
        reverse(b.begin(),b.end());
        if(ex != '?')
        cout<<a + ex + b<<"\n";
        else{
            cout<<a + b<<"\n";
        }
        
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
