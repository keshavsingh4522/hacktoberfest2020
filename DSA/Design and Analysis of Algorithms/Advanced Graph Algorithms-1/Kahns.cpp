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
    void KahnsAlgo()
    {
     
        map<int,int> indegree;
        vector<int> toplological_sort;
        queue<int> temp;
        for(int i = 0;i<vertices;i++)
        indegree[i] = 0;
        for(auto elem : edges)
        {
            for(int el : elem)
            indegree[el] ++;
        }

       for(auto elem : indegree)
       if(elem.second == 0)
       {
          temp.push(elem.first);
          
       }
            while(!temp.empty())
            {
                int curr = temp.front();
                temp.pop();
                toplological_sort.push_back(curr);
                for(int elem : edges[curr])
                {
                    indegree[elem]--;
                    if(indegree[elem] == 0)
                    temp.push(elem);
                }
            }
            if(toplological_sort.size() != this->vertices)
            cout<<"Failed\n";
            else
             {
                 cout<<"Desired Topological Sort\n";
                 for(int elem : toplological_sort)
                 cout<<elem<<" ";
             }
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
    g.KahnsAlgo();
    

}