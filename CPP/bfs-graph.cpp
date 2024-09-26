#include<iostream>
#include<list>
#include<limits>
#include<queue>

using namespace std;

class Graph{

public:
    int d;
    int p;
    list<int> *adj;
    int V;

    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u,int v){

        adj[u].push_back(v);
        cout<<u<<"->"<<v<<endl;
    }
    void BFS(int s);

};

void Graph::BFS(int s){

    bool *visited = new bool(V);
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    queue<int> q;
    visited[s] = true;

    q.push(s);

    list<int>::iterator i;
    while(!q.empty()){

        int v = q.front();
        cout<<v<<" ";
        q.pop();
        for(i = adj[v].begin();i != adj[v].end();++i){

            if(!visited[*i]){
                visited[*i] = true;
                //cout<<*i<<" pushed"<<endl;
                q.push(*i);
            }

        }

    }
}

int main()
{


    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(3, 4);
    g.BFS(2);
}
