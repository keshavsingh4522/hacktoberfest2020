#include<bits/stdc++.h>
using namespace std;
class Graph{

    vector<list<int>> edges;
    int vertices;
    public:
    Graph (int n)
    {
        this->vertices = n;
        this->edges = vector<list<int>>(n);
    }
    void AddEdge(int src,int dest)
    {
        edges[src].push_back(dest);
    }
    void TraverseNode(int currVertex,list<int> &toposort,vector<bool>&vis)
    {
        for(int elem : edges[currVertex])
        if(!vis[elem])
        TraverseNode(elem,toposort,vis);


        if(!vis[currVertex])
        toposort.push_front(currVertex);    
        vis[currVertex] = true;
        
        
    }
   void TopoSortUsingDFS()
   {
    vector<bool> vis(vertices,false);
    list<int> toposort;
    for(int i = 0;i<vertices;i++)
    TraverseNode(i,toposort,vis);
    for(int elem : toposort)
    cout<<elem<<" ";
   
   }
    
    
    


};
int main()
{
    // Sample Test Case was taken from GFG
    Graph g(6);
    g.AddEdge(5,0);
    g.AddEdge(4,0);
    g.AddEdge(4,1);
    g.AddEdge(3,1);
    g.AddEdge(2,3);
    g.AddEdge(5,2);
    g.TopoSortUsingDFS();
    

}