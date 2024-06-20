
// PLEASE READ README.TXT BEFORE USING



#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define FOR(i, a, b) for(ll i=a; i<=b; ++i) 
#define FORR(i, a, b) for(ll i=a; i>=b; --i)

using namespace std;


int ROOT;

void lift( int root, vector<vector<int>> &tree, vector<int>&parent, int up[][35] , vector<bool>&visited )
{
	if( root == ROOT ){
		FOR(k, 0 , 35-1) {
			up[root][k] = -1; 
		}
	}else{
		up[root][0]= parent[root];
		FOR(k, 1, 35-1) {
			if(up[root][k-1] == -1) up[root][k] = -1;
			else
			up[root][k] = up[up[root][k-1]][k-1];
		}
	}

	FOR(i, 0, tree[root].size()-1){
		if(!visited[tree[root][i]]) {
			parent[tree[root][i]] = root;
			visited[tree[root][i]] = 1;
		
			lift(tree[root][i], tree, parent, up, visited);
		}
	}
}




int node_at_height(int node,  int up[][35], int h ){
	if( node <= -1 ) return node;
	if( h == 0 ) return node;

	int k =0 ; int temp = h;
	while( temp%2 == 0)
	{
		temp = (temp/2);  ++k; 
	}
//	cout<<"$"<<k<<"$"; 
	return node_at_height( up[node][k] , up , h - (long)(1<<k) );
}



int main () {


	int total_nodes; cin>>total_nodes;

	vector<vector<int>> tree(total_nodes+1);
	FOR(i , 1, total_nodes-1){
		int u, v ; cin>> u>> v;
		tree[u].push_back(v); 
		tree[v].push_back(u);
	}


	ROOT = 1; // rooting tree at node 1 (global variable)

	vector<int> parent(total_nodes+1 , -1 );  // vector for storing parent of each node 

	int up[total_nodes+1][35]; memset(up , -1, sizeof(int) * (total_nodes+1) * 35);  // up[][] used for precomputation and storing dp values


	vector<bool> visited(total_nodes+1, 0); 
	visited[1]=true;


	lift(ROOT, tree, parent , up , visited );   // finally lifting 


	int queries; cin >> queries; 

	while(queries -- )
	{
		int node; cin >> node; 
		int height; cin >> height; 

		cout <<"node at give height from "<<node<< " is "<<  node_at_height (  node, up , height  )<<endl;
	}

	return  0; 
}