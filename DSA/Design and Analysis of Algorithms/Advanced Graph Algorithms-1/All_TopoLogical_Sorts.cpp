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
    void findTopoHelper(int currVertex,vector<int> toposort,vector<vector<int>> &alltoposorts,map<int,int> indegree,vector<bool>visited)
    {
        toposort.push_back(currVertex);
        visited[currVertex] = true;
        if(toposort.size() == vertices)
        {
            alltoposorts.push_back(toposort);
            return ;
        }
      for(int elem : edges[currVertex])
      indegree[elem]--;

      for(auto elem : indegree)
      if(elem.second == 0 and !visited[elem.first])
      findTopoHelper(elem.first,toposort, alltoposorts,indegree,visited);
     

    }
    
    void findAllTopologicalSorts()
    {
        vector<int> toposort;
        vector<vector<int>> alltoposorts;
        map<int,int> indegree;
        vector<bool>visited(vertices,false);
        queue<int> ans;
        for(auto elem : edges)
        {
            for(int el : elem)
            indegree[el]++;

        }
        for(int i = 0;i<vertices;i++)
        if(indegree.find(i) == indegree.end())
        indegree[i] = 0;

       
        for(auto elem : indegree)
        {
            if(elem.second == 0)
            findTopoHelper(elem.first,toposort,alltoposorts,indegree,visited);
        }
        
        cout<<alltoposorts.size()<<"\n";
        for(auto elem : alltoposorts)
        {
            for(int el : elem)
            cout<<el<<" ";
            cout<<"\n";
        }
    }
    


};
int main()
{
    // Sample Test Case was taken from GFG
    Graph g(6);
    g.AddEdge(5,2);
    g.AddEdge(5,0);
    g.AddEdge(4,0);
    g.AddEdge(4,1);
    g.AddEdge(2,3);
    g.AddEdge(3,1);
    g.findAllTopologicalSorts();
   
    

}