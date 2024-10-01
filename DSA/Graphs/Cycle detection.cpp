// finding a cycle or loop in graph

#include<bits/stdc++.h>
using namespace std;

//const int N = 10;
//vector<int> adj[N];
//
//bool vis[N+1];



bool dfs(int s, int par,bool vis[], vector<int> adj[])
{
	bool isLoop = false;
	vis[s] = true;
	
	for(int child: adj[s])
	{
	    if(vis[child] && child == par) continue;
		
		if(vis[child]) return true;
		
	    isLoop |= dfs(child,s,vis,adj); 
	}	

   return isLoop;
}
bool isCycle(int v,vector<int> adj[])
{
	bool vis[v+1] = {false};
	for(int i=1;i<=v;i++)
	{
		if(!vis[i])
		{
		    if(dfs(i,-1,vis,adj)) return true;
		}
	}
	return false;
	
}

int main()
{
	
	int v,e;
	cin>>v>>e;
	
	vector<int> adj[v+1];
	for(int i=0;i<e;i++)
	{
		int v1,v2;
		cin>>v1>>v2;
		
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	
	if(isCycle(v,adj)) cout<<"TRUE";
	else cout<<"False";
}
