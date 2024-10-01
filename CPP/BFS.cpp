#include<bits/stdc++.h>

using namespace std;

void BFS(vector<int>adj[],int u,int v,bool visited[]){
	
	list<int>queue;
	visited[u]=true;
	queue.push_back(u);
	while(!queue.empty()){
		int s=queue.front();
		cout<<s<<" ";
		queue.pop_front();

		   
		for(auto x:adj[s]){
			if(!visited[x]){
				visited[x]=true;
				queue.push_back(x);
			}
		}
	}
}

int main(){
	int v,e;
	cin>>v>>e;
	vector<int>adj[v];
	for(int i=0;i<e;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		//adj[v].push_back(u);
	}
	bool visited[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
	}
	BFS(adj,2,v,visited);
	
}
