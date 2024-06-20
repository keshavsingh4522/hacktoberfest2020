// Implemented using STL

#include<bits/stdc++.h>
using namespace std;
struct GraphInfo{
    int vertex,weight;
};
struct TrackInfo{
    int vertex,visited_from = -1,weight = INT_MAX;
};
class Graph{

    vector<list<GraphInfo > > adj;
    int no_of_vertices = 0;

    public:
    Graph(int n)
    {
        this->no_of_vertices = n;
        adj = vector<list<GraphInfo>> (n);
    }
    void assignAdjacent(int source,int destination,int dis)
    {
        GraphInfo temp;
        temp.vertex = destination;
        temp.weight = dis;
        adj[source].push_back(temp);
    }
    void display()
    {
        for(int i = 0;i<no_of_vertices;i++)
        {
            
            for(auto elem : adj[i])
            cout<<" "<<i<<" "<<elem.vertex<<" "<<elem.weight<<"\n";

        }
    }
    void disktraAlgorithm(int source = 0)
    {
        priority_queue<pair<int,int>  ,vector<pair<int,int>> ,greater<pair<int,int>>> x;
        vector<bool> visited(no_of_vertices,false);
        vector<int > vert;
        x.push({0,0});  // Dist - Source
       vector<TrackInfo> data(no_of_vertices);
       for(int i = 0;i<no_of_vertices;i++)
       data[i].vertex = i;
       data[source].visited_from = 0;
       data[source].weight = 0;
        while(!x.empty())
        {
            int curr = x.top().second;
          
            x.pop();
          
            if(!visited[curr])
            {  vert.push_back(curr);
                  visited[curr] = true;
            for(auto elem  :adj[curr])
            {
               
                if(!visited[elem.vertex] and elem.weight  + data[curr].weight< data[elem.vertex].weight )
                {
                data[elem.vertex].weight = elem.weight + data[curr].weight;
                data[elem.vertex].visited_from   = curr;
                 x.push({elem.weight + data[curr].weight,elem.vertex});
                }

            }
            }
        }

       
        for(TrackInfo elem : data)
        cout<<elem.vertex<<" "<<" "<<elem.weight<<" "<<elem.visited_from<<"\n";
      
    }



};
int main()
{
// Sample data was taken from GFG
Graph g(9);
    g.assignAdjacent(0,1,4);
    g.assignAdjacent(0,7,8);
    g.assignAdjacent(1,0,4);
    g.assignAdjacent(1,2,8);
    g.assignAdjacent(1,7,11);
    g.assignAdjacent(2,1,8);
    g.assignAdjacent(2,8,2);
    g.assignAdjacent(2,5,4);
    g.assignAdjacent(2,3,7);
    g.assignAdjacent(3,2,7);
    g.assignAdjacent(3,4,9);
    g.assignAdjacent(3,5,14);
    g.assignAdjacent(4,5,10);
    g.assignAdjacent(4,3,9);
    g.assignAdjacent(5,4,10);
    g.assignAdjacent(5,6,2);
    g.assignAdjacent(5,3,14);
    g.assignAdjacent(5,2,4);
    g.assignAdjacent(6,5,2);
    g.assignAdjacent(6,8,6);
    g.assignAdjacent(6,7,1);
    g.assignAdjacent(7,6,1);
    g.assignAdjacent(7,1,11);
    g.assignAdjacent(7,0,8);
    g.assignAdjacent(7,8,7);
    g.assignAdjacent(8,2,2);
    g.assignAdjacent(8,7,7);
    g.assignAdjacent(8,6,6);
   g.disktraAlgorithm();



}