// Can be improved using priority queue


#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<set>
using namespace std;

struct Node{
int v,weight;
Node *next;
};

struct TrackInfo{

int vertex,weight = INT_MAX,visited_from = -1;
};

Node* createNewNode(int v,int weight)
{
    Node* temp = new Node();
    temp->v = v;
    temp->weight = weight;
    temp->next = NULL;
    return temp;
}

class Graph{
    
    private:
    vector<Node*> adj;
    int n;

    public:
    Graph (int n)
    {
        this->n = n;
        adj = vector<Node*>(n,NULL);
    }
    void assignAdjacent(int source,int destination,int weight)
    {
        Node* insert = createNewNode(destination,weight);
        if(adj[source] == NULL)
        adj[source] = insert;
        else
        {
            Node* temp = adj[source];
            while(temp->next != NULL)
            temp = temp->next;
            temp->next = insert;
        }

    }
    void prims(int starting_vertex = 0)
    {
        vector<bool> vis(n,false);
        vector<TrackInfo> curr_trav(n);
        set<int> vertex;
        for(int i = 0;i<n;i++)
        curr_trav[i].vertex = i;
        vis[starting_vertex] = true,curr_trav[starting_vertex].visited_from = starting_vertex,curr_trav[starting_vertex].weight = 0;
        while(vertex.size()< n)
        {
          
            int curr,weight = INT_MAX;
            for(TrackInfo elem : curr_trav)
            if(!vis[elem.vertex] and weight > elem.weight)
            {
                weight = elem.weight;
                curr = elem.vertex;
            }
        
            vertex.insert(curr);
         
            Node* temp = adj[curr];
            vis[curr] = true;
            while(temp != NULL)
            {
                if(!vis[temp->v] and temp->weight < curr_trav[temp->v].weight )
                {
                    curr_trav[temp->v].weight = temp->weight;
                    curr_trav[temp->v].visited_from = curr;
                }
                temp = temp->next;
            
            }

        }
        for(TrackInfo elem : curr_trav)
        cout<<elem.vertex<<" "<<elem.visited_from<<" "<<elem.weight<<"\n";



    }


};
int main()
{

    // Sample was taken from GFG
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
    g.prims();
    

}