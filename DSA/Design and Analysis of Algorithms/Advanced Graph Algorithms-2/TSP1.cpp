// TSP Using BackTracking
#include<bits/stdc++.h> 
using namespace std;
class Graph{

    vector<map<int,int>> edges;
    int vertices;

    public:
    Graph(int v)
    {
        this->edges = vector<map<int,int>> (v+1);
        this->vertices = v;
    }
    void AddEdge(int src,int dest,int weight)
    {
        edges[src][dest] = weight;
        edges[dest][src] = weight;
    }
    void findOptimumPath(int startingVertex,int currVertex ,int &currcost,vector<int> currPath,vector<int>&OptimumPath,vector<bool> vis)
    {

        vis[currVertex] = true;
        currPath.push_back(currVertex);
        if(currPath.size() == vertices and edges[currPath[vertices-1]].find(startingVertex)!= edges[currPath[vertices-1]].end())
        {   
            int cost = 0;
            for(int i = 0;i< vertices-1;i++)
                cost += edges[currPath[i]][currPath[i+1]];
            cost += edges[currPath[vertices-1]][startingVertex];
            if(cost < currcost)
            {
                OptimumPath = currPath;
                currcost = cost;
            }
            return ;

        }
        for(auto elem :edges[currVertex])
        {
            if(!vis[elem.first])
            findOptimumPath(startingVertex,elem.first,currcost,currPath,OptimumPath,vis);
        }
    }
    void TSP(int startingVertex)
    {
        vector<bool> vis(vertices, false);
        vector<int> currPath,OptimalPath;
        int currCost = INT_MAX;
        findOptimumPath(startingVertex,startingVertex, currCost, currPath, OptimalPath, vis);
        cout<<currCost<<"\n";
        for(int elem : OptimalPath)
        cout<<elem<<" ";
    }
};
int main()
{
    Graph g(4);
    g.AddEdge(1,2,10);
    g.AddEdge(2,4,25);
    g.AddEdge(2,3,35);
    g.AddEdge(3,1,15);
    g.AddEdge(1,4,20);
    g.AddEdge(4,3,30);
    g.TSP(1);
    
return 0;
}
