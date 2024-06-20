#include<bits/stdc++.h> 
using namespace std;
void solve()
{
    long long int n;
    long long int ans = 0;
    cin>>n;
    vector<long long int> x(n);
    for(long long int i = 0; i < n; i++)
    cin>>x[i];
    for(long long int i =1; i < n; i++)
    {
        if(x[i] < x[i-1])
        ans += x[i-1] - x[i],x[i] = x[i-1];
    }
    cout<<ans;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
