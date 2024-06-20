#include<iostream>
#include<string>
#include<vector>
#include<queue>
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
 
  void bfs(int s)
  {
      queue<Node*> data;
      queue<int> elem;
      data.push(adj[s]);
      elem.push(s);
      visited[s] = true;

      while(!data.empty())
      {
          int check = elem.front();
          cout<<check<<" ";
          Node *temp = data.front();
          elem.pop();
          data.pop();
          while(temp!= NULL)
          {
              if(!visited[temp->vertex])
              {
                visited[temp->vertex] = true;
                data.push(adj[temp->vertex]);
                elem.push(temp->vertex);

              }
              temp = temp->next;
          }
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
    g.bfs(2);
}

