// I am not implementing for undirected one because it will be quite similar
//This graph uses adjacency list
// Use similar approach for weighted graph 
#include<iostream>
#include<vector>
using namespace std;
struct Node {
    int data ;
    Node* next;
};
Node* createNewNode(int elem)
{
    Node* temp = new Node();
    temp->data = elem;
    temp->next = NULL;
    return temp;
}
class Graph
{
    vector<Node*> adj;
    int vertices;
    
    public:
    Graph (int n )
    {
          this->vertices = n;
          adj = vector<Node*> (vertices,NULL);
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
    int outdegree(int key)
    {
        int ans = 0;
        Node* temp = adj[key];
        while(temp!= NULL)
        {
            temp = temp->next;
            ans ++;
        }
        return ans ;
    } 
    int indegree(int key)
    {
        int ans = 0;
        Node *temp;
        for(Node* elem : adj)
        {
            temp = elem;
            while(temp!= NULL)
            {
                if(temp->data == key)
                ans++;
                temp = temp->next;
            }
        }
        return ans;

    }
    void adjacentvertices(int key)
    {
      Node* temp = adj[key];
      while(temp!= NULL)
      {cout<<temp->data<<" ";
      temp = temp->next;}
    }
    int countedges()
    {
         int ans = 0;
        Node *temp;
        for(Node* elem : adj)
        {
            temp = elem;
            while(temp!= NULL)
            {
                temp = temp->next;
                ans ++;
            }
        }
        return ans;
    }
    void displaygraph()
    {

        for(int i = 0;i<vertices;i++)
        {
            cout<<"Adjacent to "<<i<<":";
            Node *temp = adj[i];
            while(temp != NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"\n";
        }
    }

};
int main()
{
    int elem, key ,choice,n,x;
    cout<<"Constructing a directed graph...\nEnter number of vertices(0..n)\n";
    cin>>n;
    Graph graph(n);
    for(int i = 0;i<n;i++)
    {
        cout<<"\nEnter number elements adjacent to "<<i<<":";
        cin>>x;
        cout<<"\n Enter the adjacent elements: ";
        for(int j = 0;j<n;j++)
        {cin>>elem;
        graph.assignadjacent(i,elem);}

    }

    while(true)
    {
      cout<<"\nGraph menu\n: 1 Get in-degree of node\n2. Get out-degree of a node\n3. Get number of edges\n4.Get adjacent vertices\n5.Display Graph\n6. Exit ";
      cout<<"\n Enter your choice:";
      cin>>choice;
      switch (choice)
      {
     case 1: cout<<"\nEnter node whose in - degree is to be calculated: ";
     cin>>key;
     cout<<"\n In degree of desired node is: "<<graph.indegree(key);
     break;

     case 2: cout<<"\nEnter node whose out - degree is to be calculated: ";
     cin>>key;
     cout<<"\n out degree of desired node is: "<<graph.outdegree(key);
     break;

     case 3: cout<<"\nNumber of edges in the graph are: "<<graph.countedges();
     break;
     
     case 4: 
     cout<<"\nEnter elem whose adjancent elements you want to find: ";
     cin>>key;
     cout<<"\n Desired adjacent elements are: ";
     graph.adjacentvertices(key);
     break;


     case 5:
     cout<<"\nDisplaying graph..\n";
     graph.displaygraph();
     cout<<"\n";
     break;

     case 6:
     cout<<"Exiting..";
     exit(1);
     break;

     default:
     cout<<"Wrong choice entered.\n";
     break;

      }
    }
}