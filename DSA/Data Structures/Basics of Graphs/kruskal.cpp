#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class DisjointSet {

private:
int *rank,*parent,n;

public:
    DisjointSet(int n)
    {
        rank = new int [n];
        parent = new int [n];
        this->n = n;
    
      for(int i = 0;i<n;i++)
        parent[i] = i;
    }
    int find(int x)
    {
        if(parent[x]!= x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void Union(int x,int y)
    {
      int xpar = find(x);
      int ypar = find(y);

      if(xpar == ypar)
      return;

      if(rank[xpar]<rank[ypar])
      parent[xpar] = ypar;

      else if(rank[xpar]>rank[ypar])
      parent[ypar] = xpar;

      else{
          parent[ypar] = xpar;
          rank[xpar] = rank[xpar]  + 1;
      }

    }
    bool detectCycle(int a,int b)
    {
        if(find(a) == find(b))
        return true;

        return false;
    }


};
struct Edge{
int source,destination,distance;
};
Edge createNewNode(int source,int destination,int distance)
{
    Edge temp;
    temp.source = source;
    temp.destination = destination;
    temp.distance = distance;
    return temp;

}
bool comparator(Edge e1,Edge e2)
{

return e1.distance<=e2.distance;
       
} 
class Graph
{
    private:
   vector<Edge> edges;

   public:
  
   void insertEdge(int source,int destination,int distance)
   {
       Edge insert = createNewNode(source,destination,distance);
       edges.push_back(insert);

   }
   void kruskal(int vertices)
   {   int cost = 0;
       sort(edges.begin(),edges.end(),comparator);
       DisjointSet obj(vertices);
       for(auto edge : edges)
       {
             if(!obj.detectCycle(edge.source,edge.destination))
             {
                 cout<<edge.source<<"-->"<<edge.destination<<" Distance: "<<edge.distance<<"\n";
                 cost += edge.distance;
                 obj.Union(edge.source,edge.destination);
             }
             cout<<"Total Cost: "<<cost;
       }
   }
};
int main()
{
    // Sample Data was taken from GFG
    Graph g;
    g.insertEdge(0,1,10);
    g.insertEdge(0,2,6);
    g.insertEdge(0,3,5);
    g.insertEdge(1,3,15);
    g.insertEdge(2,3,4);
    g.kruskal(4);

}
