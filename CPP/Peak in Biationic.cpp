#include <bits/stdc++.h>
using namespace std;
#define ll long long

///////////////////////////----SKIP THIS------//////////////////////////////////////

///////////////////////////////////---READ FROM HERE --------///////////////////////////////////////////
ll peak_in_bitonic(vector<ll>a,ll l,ll h)
{
    if(h<l)
        return -1;

    ll mid= l + (h-l)/2;

    if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
        return mid;

    else if(a[mid]<a[mid-1])
        return peak_in_bitonic(a,l,mid-1);
    else
        return peak_in_bitonic(a,mid+1,h);
}
/////////////////--Solve----/////////////////////////
void solve()
{

    ll n,k;cin>>n>>k;
    vector<ll>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll  temp = peak_in_bitonic(a,0,n-1);
    cout<<temp;
    ////////--return-////////////
    return;
}
//////////////////////////////////////------Main--------///////////////////////////////////////////////
int main()
{

    ///////////input output non terminal/////////
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
        ///////////////////////

    ///////fast-io///////
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ////////////

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
        cout << "\n";
    }

    return 0;
}
