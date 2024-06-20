#include<bits/stdc++.h> 
#define ll long long 
using namespace std;
void solve()
{
    ll n ;
    cin>>n;
    while(n != 1)
    {
        cout<<n<<" ";
        n = n%2 == 0 ? n/2 : 3*n + 1;

    }
    cout<<n;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
