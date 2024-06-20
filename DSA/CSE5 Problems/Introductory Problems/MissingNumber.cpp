#include<bits/stdc++.h> 
using namespace std;
void solve()
{
    int n ,temp;
    cin>>n;
    vector<int> x(n+1,0);
    for(int i = 0; i < n-1 ;i++)
    {
        cin>>temp;
        x[temp]=1 ;
    }
    for(int i = 1; i <= n ; i++)
    if(x[i] == 0)
    {
        cout<<i;
        break;
    }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
