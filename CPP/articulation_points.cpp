#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define FLSH fflush(stdout)
#define int long long int
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define in insert
#define MOD 1000000007
#define debug(x) cout << "[ " << #x  << " : " << x << " ]" << endl;

using namespace std;

void dfs(int s, std::vector<std::vector<int>> &e, std::vector<int> &desc, 
			std::vector<int> &low, std::vector<int> &parent, std::vector<bool> &ap,
			std::vector<bool> &visited){

	static int time = 0;

	desc[s] = low[s] = ++time;
	int child_count = 0;
	visited[s] = true;
	for (int i = 0; i < e[s].size(); ++i)
	{
		int node = e[s][i];
		if(!visited[node]){
			child_count++;
			parent[node] = s;
			dfs(node, e, desc, low, parent, ap, visited);

			low[s] = min(low[s], low[node]);

			if(parent[s] != -1 && low[node] >= desc[s])
				ap[s] = true;
			if(parent[s] == -1 && child_count > 1)
				ap[s] = true;
		}
		else{
			low[s] = min(low[s], desc[node]);
		}
	}
}

signed main(){

	int n;
	cin >> n;
	int m;
	cin >> m;
	std::vector<std::vector<int>> e(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	std::vector<int> desc(n, -1);
	std::vector<int> low(n, -1);
	std::vector<int> parent(n, -1);
	std::vector<bool> ap(n, false);
	std::vector<bool> visited(n, false);

	dfs(0, e, desc, low, parent, ap, visited);

	int count = 0;
	cout << "aps: ";
	for (int i = 0; i < n; ++i)
	{
		count += ap[i];
		if(ap[i])
			cout << i << " ";
	}
	cout << endl;

	cout << count << endl;

}