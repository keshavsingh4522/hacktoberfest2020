#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e15
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
int n, m, k;
vector<vector<pii> > adj;
vector<vi> d;
vector<vi> routes;
 
void dijkstra(int i)
{
	set<pii> s;
	d[i][i] = 0;
	s.insert({0, i});
 
	while (!s.empty())
	{
		int v = s.begin()->ss;
		s.erase(s.begin());
 
		for (pii &nb : adj[v])
		{
			int w = nb.ss;
			int to = nb.ff;
 
			if (d[i][v] + w < d[i][to])
			{
				s.erase({d[i][to], to});
				d[i][to] = d[i][v] + w;
				s.insert({d[i][to], to});
			}
		}
	}
}
 
int get(int i, int j)
{
	int ans = 0;
	for (vi &v : routes)
		ans += min({d[v[0]][v[1]], d[v[0]][i] + d[j][v[1]], d[v[1]][i] + d[j][v[0]]});
 
	return ans;
}
 
int32_t main()
{
	FIO;
	cin >> n >> m >> k;
	adj.resize(n + 1);
 
	vector<vi> edg;
 
	while (m--)
	{
		int i, j, w; cin >> i >> j >> w;
		edg.pb({i, j});
		adj[i].pb({j, w});
		adj[j].pb({i, w});
	}
 
	d.assign(n + 1, vi(n + 1, inf));
 
	for (int i = 1; i <= n; ++i)
		dijkstra(i);
 
	routes.assign(k, vi(2));
 
	for (vi &v : routes)
		cin >> v[0] >> v[1];
 
	int ans = inf;
 
	for (vi &v : edg)
		ans = min(ans, get(v[0], v[1]));
 
	cout << ans << '\n';
	return 0;
}
