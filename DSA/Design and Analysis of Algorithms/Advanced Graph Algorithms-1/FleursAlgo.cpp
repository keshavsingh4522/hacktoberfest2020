#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    vector<map<int,int>> edges;
    int vertices;

    Graph (int n)
    {
        this->vertices = n;
        this->edges = vector<map<int,int>>(n);
    }
    void addEdge(int src,int dest)
    {
        edges[src][dest] = 0;
        edges[dest][src] = 0;
    }
 bool checkBridgeEdge(int src, int dest)
 {
     
     edges[src][dest] = 1;
     edges[dest][src] = 1;
     int curr1 = src;
     queue<int> temp1;
     temp1.push(curr1);
     vector<bool> vis1(vertices, false);
     vis1[curr1] = true;
     set<int> vert1;
     while(!temp1.empty())
     {
         int curr = temp1.front();
         temp1.pop();
        vert1.insert(curr);
         for(auto elem : edges[curr])
         if(!vis1[elem.first] and elem.second != 1)
         {
             vis1[elem.first] = true;
             temp1.push(elem.first);
         }
     }
     int curr = dest;
     queue<int> temp;
     temp.push(curr);
     vector<bool> vis(vertices, false);
     vis[curr] = true;
     set<int> vert;
     while(!temp.empty())
     {
         int curr = temp.front();
         temp.pop();
        vert.insert(curr);
         for(auto elem : edges[curr])
         if(!vis[elem.first] and elem.second != 1)
         {
             vis[elem.first] = true;
             temp.push(elem.first);
         }
     }
    edges[src][dest] = 0;
    edges[dest][src] = 0;
     return vert.size() != vert1.size();
 }
void findEulerHelper(int currVertex,vector<pair<int,int>> &ans)
{
    for(auto elem: edges[currVertex])
    {

        
        if(elem.second != 1 and !checkBridgeEdge(currVertex,elem.first))
        {        
        
            ans.push_back({currVertex,elem.first});
            edges[currVertex][elem.first] = 1;
            edges[elem.first][currVertex] = 1;
            findEulerHelper(elem.first, ans);
        }
    
    }
    for(auto elem : edges[currVertex])
    {
        if(elem.second != 1)
        {
        
            ans.push_back({currVertex,elem.first});
            edges[currVertex][elem.first] = 1;
            edges[elem.first][currVertex] = 1;

            findEulerHelper(elem.first, ans);
           
        }
    }

}
void printEulerPath()
{
    map<int,int> deg;
    vector<pair<int,int>> ans;
    int curr = 0;
    for(auto elem : edges)
    {
        for(auto el : elem)
        deg[el.first]++;
    }
    for(auto elem : deg)
    {
        if(elem.second%2 != 0)
        {
            curr = elem.first;
            break;
        }
    }
    findEulerHelper(curr, ans);
    for(auto elem :ans)
    cout<<elem.first<<" "<<elem.second<<"\n";

}


 


};
int main()
{

    // Sample was taken from GFG

  Graph g3(5);
  g3.addEdge(1, 0);
  g3.addEdge(0, 2);
  g3.addEdge(2, 1);
  g3.addEdge(0, 3);
  g3.addEdge(3, 4);
  g3.addEdge(3, 2);
  g3.addEdge(3, 1);
  g3.addEdge(2, 4);
  g3.printEulerPath();

    return 0;

}