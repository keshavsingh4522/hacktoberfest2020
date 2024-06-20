#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    vector<list<pair<int,int>>> edges;
    int vertices;

    Graph (int n)
    {
        this->vertices = n;
        this->edges = vector<list<pair<int,int>>>(n);
    }
    void addEdge(int src,int dest)
    {
        edges[src].push_back({dest,0});
        // edges[dest].push_back({src,0});
    }
    void findEulerCircuit(int Vertex,vector<int> &EulerCircuit)
    {
        for(auto &elem : edges[Vertex])
        {

            if(elem.second != 1)
            {
            elem.second = 1;
            findEulerCircuit(elem.first,EulerCircuit);
            }
        }
        EulerCircuit.push_back(Vertex);
    }


};
int main()
{

    // Sample was taken from GFG
    
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    vector<int> EulerCircuit;
    g2.findEulerCircuit(0,EulerCircuit);
    for(int elem : EulerCircuit)
    cout<<elem<<" ";
    cout<<"\n";
  

  
    return 0;

}