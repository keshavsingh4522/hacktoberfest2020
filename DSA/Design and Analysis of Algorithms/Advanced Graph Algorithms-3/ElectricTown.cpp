// Not Finished Yet

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
    void Display()
    {
         for(int i = 0; i < vertices;i++)
        {
        cout<<i<<": ";
        for(auto elem : edges[i])
        cout<<elem.first<<"->"<<elem.second<<"\n";
         }
    }
    long long int flordfulkerson(int src,int sink)
    {
        long long int flow = 0;
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
    int n,m,src,dest,weight,t,a,b;
    cin>>n>>m;
    Graph g(n);
    while(m--)
    {   cin>>src>>dest>>weight;
        g.addEdge(src-1,dest-1,weight);
    }
    cin>>t;
    while(t--)
    {   Graph k = g;
        cin>>a>>b;
        cout<<k.flordfulkerson(a-1,b-1)<<"\n";
    }

        

}