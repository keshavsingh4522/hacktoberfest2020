// I am not implementing for undirected one because it will be quite similar
//This graph uses adjacency matrix
// Use similar approach for weighted graph 
#include<iostream>
using namespace std;
class Graph
{
    int arr[100][100] = {{0}};
    int vertices;

    
    public:
    Graph (int n )
    {
        this->vertices = n;
    }
    void assignadjacent(int key,int ass)
    {
        arr[key][ass] = 1;
    }
    int outdegree(int key)
    {
       int ans = 0;
       for(int i = 0;i<vertices;i++)
       if(arr[key][i] == 1)
       ans++;
       return ans;
    } 
    int indegree(int key)
    {
       int ans = 0;
       for(int i = 0;i<vertices ;i++)
       if(arr[i][key] == 1)
       ans ++;
       return ans;

    }
    void adjacentvertices(int key)
    {
      for(int i=0;i<vertices; i++)
      if(arr[key][i] == 1)
      cout<<i<<" ";

    }
    int countedges()
    {
        int ans = 0;
        for(int i = 0;i<vertices;i++)
        for(int j = 0;j<vertices ; j++)
        if(arr[i][j] == 1)
        ans ++;
        return ans;
       
    }
    void displaygraph()
    {
         for(int i = 0;i<vertices;i++)
         {
             cout<<"\nVertices adjancent to"<<i<<"are: ";
             for(int j = 0;j<vertices ; j++)
             if(arr[i][j] == 1)
             cout<<j<<" ";
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