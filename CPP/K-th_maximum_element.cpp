#include <bits/stdc++.h>
using namespace std;
#define int long long int 
#define REP(i,k,n) for (int i = k ; i < n; i++)
#define REPD(i,k,n) for (int i = k; i >= n; i--)
#define all(v) v.begin(),v.end() 
#define SZ(x) ((int)(x).size())
#define br cout <<"\n";
// bool cmp( pair<int,int> a , pair<int,int> b ){
//     if( a.first == b.first )
//         return (a.second > b.second);
//     return a.first < b.first ;
// }
const int MOD = 1000000007;
const int INF = 1e18;

void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	set<int> s(arr, arr + n);
	set<int>::iterator itr = s.begin();
	advance(itr, k - 1); 
	cout << *itr << "\n";
}


int32_t main() {
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin);  
        freopen("output.txt", "w", stdout); 
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }    
    return 0;
}
