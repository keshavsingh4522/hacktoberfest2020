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
    void addEdge(int src,int dest)
    {
        edges[src].push_back(dest);
        edges[dest].push_back(src);
    }
    bool connected()
    {
        queue<int> temp;
        vector<bool> vis(vertices,false);
        temp.push(0);
        vector<int> reached;
        while(!temp.empty())
        {   
            int curr = temp.front();
            vis[curr] = true;
            reached.push_back(curr);
            temp.pop();
            for(int elem : edges[curr])
            if(!vis[elem])
            temp.push(elem),vis[elem] = true;
        }
        return int(reached.size()) == vertices;
    }
    void checkeulerain()
    {
        if(!(this->connected()))
       cout<<"Not Eulerian\n";

       else
       {
           int evens = 0,odds = 0;
           for(int i = 0;i<vertices;i++)
           {
               if(edges[i].size()%2 == 0)
               evens ++;
               else
                odds++;
           }
            if(odds == 0)
            cout<<"Eulerian Circuit\n";
            else if (odds == 2)
            cout<<"Eulerian Path\n";
            else
            cout<<"Not Eulerian\n";
       }

    }
    
    


};
int main()
{

    // Sample was taken from GFG
     // Let us create and test graphs shown in above figures
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.checkeulerain();
  
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    g2.checkeulerain();

    Graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    g3.checkeulerain();
  
    // Let us create a graph with 3 vertices
    // connected in the form of cycle
    Graph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    g4.checkeulerain();
  

  
    return 0;

}