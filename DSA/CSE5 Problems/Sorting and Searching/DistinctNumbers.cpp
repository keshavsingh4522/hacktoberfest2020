#include<bits/stdc++.h> 
#define ll long long 
using namespace std;
void solve()
{
    ll n ,ans;
    cin>>n;
    ans = n;
    vector<ll> x(n);
    for(ll i = 0; i < n ; i++)
    cin>>x[i];
    sort(x.begin(),x.end());
    for(ll i = 0; i < n-1; i++)
    if(x[i] == x[i+1])
    ans--;
    cout<<ans;

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
