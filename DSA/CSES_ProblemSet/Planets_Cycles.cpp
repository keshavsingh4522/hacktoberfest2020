#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
/*####################################################################*/
#define rep(i,a,b) for(int i=a;i<b;++i)
#define Rep(i,a,b) for(int i=a;i<=b;++i)
#define Rrep(i,a,b) for(int i=a;i>b;--i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
#define sq(a) (a)*(a)
#define nitro std::ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define text std::cerr<<"SacredCoupoid08\n"
#define endl '\n'
#define all(c) (c).begin(),(c).end()
#define U 1000000007
#define N 100005
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
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
/*####################################################################*/
using namespace std;
using namespace __gnu_pbds;
/*####################################################################*/
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');std::cerr.write(names,
	 comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
template<class T> T gcd(T a,T b){return (b==0)? a:gcd(b,a%b); }
/*####################################################################*/
typedef long long ll;
typedef std::vector< ll > vi;
typedef std::pair<ll, ll> pi;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
        tree_order_statistics_node_update>
        pbds;
/*####################################################################*/
ll toint(const string &s) {stringstream ss; ss << s; ll x; ss >> x; return x;}
string tostring ( ll number ){stringstream ss; ss<< number; return ss.str();}
ll pow(ll a,ll p,ll m=U)
{ll res=1;while(p>0){if(p&1)res =(res*a)%m;a=(a*a)%m;p>>=1;}return res;}
/*####################################################################*/
const long double pie=3.141592653589793238462643383;
auto _C=clock();
/*####################################################################*/
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
vi a,vis,res,last;
vector <vi> adj;
void dfs_rev(int u,int len)
{
	if(!vis[u])
		vis[u]=1;
	res[u]=len;
	for(auto &it: adj[u])
		if(res[it]==-1)
			dfs_rev(it,len+1);
}
void dfs(int u)
{
	int v=u;
	int cnt=0;
	while(1)
	{
		cnt++;
		int cyclen=cnt-last[v];
		if(vis[v])
		{
			u=v;
			while(res[u]==-1)
			{
				res[u]=cyclen;
				u=a[u];
			}
			for(auto &edge:adj[v])
				if(res[edge]==-1)
					dfs_rev(edge,res[v]+1);
			break;
		}
		vis[v]=1;
		last[v]=cnt;
		v=a[v];
	}
}
signed main()
{		
	nitro;
	int CASE=1;
	//cin>>CASE;
	while(CASE--)
	{
		int n;
		cin>>n;
		a.resize(n+1);
		adj.resize(n+1);
		vis.resize(n+1);
		res.resize(n+1,-1);
		Rep(i,1,n)
		{
			cin>>a[i];
			adj[a[i]].pb(i);
		}
		Rep(i,1,n)
		{
			if(!vis[i])
			{
				last.resize(n+1);
				dfs(i);
			}
		}
		Rep(i,1,n)
		cout<<res[i]<<" ";
		cout<<endl;
	}
	
	
	
	
 
//cerr<<"\n\n\nTime elapsed: "<<(double)(clock()-_C)*1000.0/CLOCKS_PER_SEC<<"ms\n";		
 
	return 0;
}
 
