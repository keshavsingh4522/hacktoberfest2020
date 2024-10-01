#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define Rep(i,a,b) for(int i=a;i<=b;++i)
#define Rrep(i,a,b) for(int i=a;i>b;--i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define sq(a) (a)*(a)
#define nitro std::ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define debug(x) std::cerr<<#x<<"="<<x<<'\n'
#define text std::cerr<<"SacredCoupoid08\n"
#define endl '\n'
#define all(c) (c).begin(),(c).end()
#define U 1000000007
#define N 1000006
#define sz(c) (int)c.size()
#define pb push_back
#define pv(x) for(auto y:x)    cout<<y<<" ";    cout<<'\n';
#define fr first
#define sc second
#define ppb pop_back
#define Max(a,b) a=max(a,b)
#define Min(a,b) a=min(a,b)
#define int ll
#define tr(c,it) for(typeof(c.begin()) it= c.begin();it != c.end();it++)
#define ri(X) scanf("%lld", &(X))
#define rii(X, Y) scanf("%lld%lld", &(X), &(Y))
#define riii(X, Y, Z) scanf("%lld%lld%lld", &(X), &(Y), &(Z))
#define dri(X) ll (X); scanf("%lld", &X)
#define drii(X, Y) ll X, Y; scanf("%lld%lld", &X, &Y)
#define driii(X, Y, Z) int X, Y, Z; scanf("%lld%lld%lld", &X, &Y, &Z)
#define rs(X) scanf("%s", (X))
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
typedef long long ll;
typedef std::vector< ll > vi;
typedef std::pair<ll, ll> pi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
        tree_order_statistics_node_update>
        pbds;
const double pie = 3.14159265358979323846;
auto _C=clock();
/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;         ;;    ;;     ;;;;;;;     ;;     ;;  ;;;;     ;;
 ;;       ;;   ;;  ;;   ;;    ;;    ;;     ;;  ;; ;;    ;;
  ;;     ;;   ;;    ;;  ;;    ;;    ;;     ;;  ;;  ;;   ;;
   ;;   ;;    ;;;;;;;;  ;;;;;;;     ;;     ;;  ;;   ;;  ;;
    ;; ;;     ;;    ;;  ;;   ;;      ;;   ;;   ;;    ;; ;;
     ;;;      ;;    ;;  ;;    ;;       ;;;     ;;     ;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/
int dp[N];
int fun(int n)
{
	if(n<0) return 0;
	if(n==0) return 1;
	if(dp[n]!=-1) return dp[n];
	int ans=0;
	Rep(i,1,6)
	ans=(ans+fun(n-i))%U;
	dp[n]=ans;
	return ans;
	
}
signed main()
{		
	nitro;
	int CASE=1;
	//ri (CASE);
	//cin>>CASE;
	while(CASE--)
	{
		int n;
		cin>>n;
		memset(dp,-1,sizeof dp);
		cout<<fun(n)<<endl;
		
	}
	
	
	
	
 
//cerr<<"\n\n\nTime elapsed: "<<(double)(clock()-_C)*1000.0/CLOCKS_PER_SEC<<"ms\n";		
 
	return 0;
}
