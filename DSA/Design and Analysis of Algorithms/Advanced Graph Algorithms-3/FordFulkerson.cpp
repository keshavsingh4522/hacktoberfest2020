#include<bits/stdc++.h>
using namespace std;
class Graph
{
    vector<map<int,int>> edges;
    int vertices;
    public:
    Graph(int n)
    {
        this->vertices = n;
        this->edges = vector<map<int,int>> (n);
    }
    void addEdge(int src,int dest,int flow)
    {
        edges[src][dest] = flow;
    }
    vector<int> DFS(int source,int sink)
    {
        stack<int> data;
        vector<bool> vis(vertices,false);
        vector<int> ans;
        vector<int> parent(vertices,-1);
        data.push(source);
        vis[source] = true;
        bool check = false;
        while(!data.empty())
        {
            int curr = data.top();
            data.pop();
            for(auto elem : edges[curr])
            {
                if(!vis[elem.first] and elem.second> 0)
                {
                    vis[elem.first] = true;
                    data.push(elem.first);
                    parent[elem.first] = curr;
                    if(elem.first == sink)
                    {   
                        check = true;
                        break;
                    }
                }
            }
            if(check)
            break;
           
               
        }
        int curr = sink;
        while(parent[curr] != -1)
        ans.push_back(curr),curr = parent[curr];
        if(ans.size() != 0)
        ans.push_back(0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int flordfulkerson(int src,int sink)
    {
        int flow = 0;
        vector<int> temp = DFS(src,sink);

        while(temp.size() != 0)
        {
        
            
        int maxCap = INT_MAX;
        for(int i = 0 ; i < temp.size()- 1; i++)
        maxCap = min(edges[temp[i]][temp[i+1]],maxCap);
        flow += maxCap;
  
        for(int i = 0 ; i < temp.size()-1 ; i++ )
        {
            edges[temp[i+1]][temp[i]] += maxCap;
            edges[temp[i]][temp[i+1]] -= maxCap;
        }
      
       temp = DFS(src,sink);

   }


        return flow;
    }
};
int main()
{
    // Sample was taken from GFG
    Graph g(6);
    g.addEdge(0,1,16);
    g.addEdge(1,3,12);
    g.addEdge(3,5,20);
    g.addEdge(4,5,4);
    g.addEdge(2,4,14);
    g.addEdge(0,2,13);
    g.addEdge(1,2,10);
    g.addEdge(2,1,4);
    g.addEdge(3,2,9);
    g.addEdge(4, 3, 7);
    cout<<g.flordfulkerson(0, 5);
        

}