#include<bits/stdc++.h> 
using namespace std;
void solve()
{
     long long int n, k,ans=0;
     cin>>n>>k;
     vector<long long int>x(n);
     for(long long int i = 0;i<n;i++)
     cin>>x[i];
     sort(x.begin(),x.end());
     for(long long int i = 0;i<n-k;i++)
     ans += x[i];
     cout<<ans;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
