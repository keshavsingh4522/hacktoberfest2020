#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const ll N=2e5+5 ;
vector<ll> v[N] ;
ll dp[N][2] ;

void DFS(ll x,ll p){
    for(int i : v[x]){
        if (i!=p){
            DFS(i,x) ;
            dp[x][0]+=max(dp[i][0],dp[i][1]) ;
        }
    }
    for(int i : v[x]){
        if (i!=p){
            dp[x][1]=max(dp[x][1],1+dp[x][0]-max(dp[i][0],dp[i][1])+dp[i][0]) ;
        }
    }
}

int main() {
    IOS ;
    ll tc=1 ; 
	// cin>>tc ;
	while(tc--){
        ll n,x,y ;
        cin>>n ;
        while(--n){
            cin>>x>>y ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        DFS(1,-1) ;
        cout<<max(dp[1][0],dp[1][1])<<endl ;
    }
	return 0;
}
