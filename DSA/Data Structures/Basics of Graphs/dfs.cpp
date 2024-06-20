#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
struct Node{

  int vertex; 
  Node* next;
};
Node* createNewNode(int elem)
{
    Node* temp = new Node();
    temp->vertex = elem;
    temp->next = NULL;
    return temp;
}
class Graph{

private:
vector<Node*> adj;
vector<bool> visited;
int vertices;

public:
Graph(int n)
{
  this->vertices = n;
  adj = vector<Node*> (vertices,NULL);
  visited = vector<bool> (vertices,false);

}
 void assignadjacent(int key,int ass)
    {
        Node* temp = adj[key];
        if(temp == NULL)
        adj[key] = createNewNode(ass);
        else{
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = createNewNode(ass);
        }
    }
    void dfs(int v)
    {
        visited[v] = true;
        cout<<v<<" ";
        Node *temp = adj[v];
        while(temp!=NULL)
        {
            if(!visited[temp->vertex])
            dfs(temp->vertex);
            temp = temp->next;
        }
    }


     void displaygraph()
    {

        for(int i = 0;i<vertices;i++)
        {
            cout<<"Adjacent to "<<i<<":";
            Node *temp = adj[i];
            while(temp != NULL)
            {
                cout<<temp->vertex<<" ";
                temp = temp->next;
            }
            cout<<"\n";
        }
    }
 
};
int main()
{

    // Sample data was taken from GFG
   Graph g(4);
    g.assignadjacent(0, 1);
    g.assignadjacent(0, 2);
    g.assignadjacent(1, 2);
    g.assignadjacent(2, 0);
    g.assignadjacent(2, 3);
    g.assignadjacent(3, 3);
    g.displaygraph();
    g.dfs(2);
}

