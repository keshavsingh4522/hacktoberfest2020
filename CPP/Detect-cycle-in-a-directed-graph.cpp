class Solution
{   public:
    bool dfsCycle(int i,vector<int>adj[],int vis[],int dfsVis[]){
        vis[i]=1;
        dfsVis[i]=1;
        for(auto u :adj[i]){
            if(!vis[u]){
                if(dfsCycle(u,adj,vis,dfsVis))return true;
            }
            else if(dfsVis[u])return true;
        }
        dfsVis[i]=0;
        return false;
    }
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{   
	    int vis[V];
	    int dfsVis[V];
	    memset(vis,0,sizeof(vis));
	    memset(dfsVis,0,sizeof(dfsVis));
	   	for(int i=0;i<V;i++){
	   	    if(!vis[i])
	   	    if(dfsCycle(i,adj,vis,dfsVis))return true;
	   	}
	   	return false;
	}
};
