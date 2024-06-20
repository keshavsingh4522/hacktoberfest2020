#include<bits/stdc++.h> 
using namespace std;
void solve()
{
    int n,ans = 1,candies = 1;
    cin>>n;
    vector<int> x(n);
    for(int i = 0;i<n;i++)
    cin>>x[i];
    sort(x.begin(),x.end());
    for(int i = 1;i<n;i++)
    {
        if(x[i]!= x[i-1])
        candies++;
        
        ans += candies;
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
