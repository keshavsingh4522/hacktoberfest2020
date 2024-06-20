// Hamiltonian using BackTracking 
#include<bits/stdc++.h>
using namespace std;
class Graph{
    vector<list<int>> edges;
    int vertices;
    
    public:
    Graph(int n)
    {
        this->vertices = n;
        this->edges = vector<list<int>>(n);
    }
    void addEdge(int src, int dest)
    {
        edges[src].push_back(dest);
        edges[dest].push_back(src);
    }
    void PathFinder(int currVertex,vector<int> path,vector<vector<int>> &HamiltonianPath,vector<bool> vis)
    {
            path.push_back(currVertex);
            vis[currVertex] = true;
            
            if(path.size() == vertices)
            {
                HamiltonianPath.push_back(path);
                return ;
            }
            for(int elem : edges[currVertex])
            if(!vis[elem])
            PathFinder(elem,path,HamiltonianPath,vis);
    }
    void findHamilTonianPaths()
    {
        vector<int> path;
        vector<vector<int>> HamiltonianPath;
        vector<bool> vis(vertices,false);
        for(int i = 0;i<vertices;i++)
        PathFinder(i,path,HamiltonianPath,vis);
        for(auto elem : HamiltonianPath)
        {
            for(int el : elem)
            cout<<el<<" ";
            cout<<"\n";
        }
    }
};
int main()
{
    
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
    g.findHamilTonianPaths();
    
}