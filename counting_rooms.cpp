#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqmax             priority_queue<int>
#define pqmin             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             2e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FastIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//if infinite loop====> tools-> cancel build
// void deepshit() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);

// 	freopen("output.txt", "w", stdout);
// #endif
// 	FastIO
// }
int n, m;
void dfs(vector<string>& grid, int x, int y) {
	grid[x][y] = '*';
	if (x - 1 >= 0 && grid[x - 1][y] == '.')
		dfs(grid, x - 1, y);
	if (x + 1 < n && grid[x + 1][y] == '.')
		dfs(grid, x + 1, y);
	if (y - 1 >= 0 && grid[x][y - 1] == '.')
		dfs(grid, x, y - 1);
	if (y + 1 < m && grid[x][y + 1] == '.')
		dfs(grid, x, y + 1);
	return;
}


int32_t main() {
	// deepshit();

	cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '.') {
				cnt++;
				dfs(grid, i, j);
			}
		}
	}
	cout << cnt;
	return 0;
}
