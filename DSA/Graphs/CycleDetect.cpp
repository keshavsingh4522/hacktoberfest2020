#include<iostream>
#include <list>
#include <limits.h>
using namespace std;

// Class for an undirected graph
class Graph
{
	
	// No. of vertices
	int V;

	// Pointer to an array
	// containing adjacency lists
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[],
							int parent);
public:

	// Constructor
	Graph(int V);

	// To add an edge to graph
	void addEdge(int v, int w);

	// Returns true if there is a cycle
	bool isCyclic();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	
	// Add w to v’s list.
	adj[v].push_back(w);

	// Add v to w’s list.
	adj[w].push_back(v);
}

// A recursive function that
// uses visited[] and parent to detect
// cycle in subgraph reachable
// from vertex v.
bool Graph::isCyclicUtil(int v,
				bool visited[], int parent)
{
	
	// Mark the current node as visited
	visited[v] = true;

	// Recur for all the vertices
	// adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i !=
					adj[v].end(); ++i)
	{
		
		// If an adjacent vertex is not visited,
		//then recur for that adjacent
		if (!visited[*i])
		{
		if (isCyclicUtil(*i, visited, v))
			return true;
		}

		// If an adjacent vertex is visited and
		// is not parent of current vertex,
		// then there exists a cycle in the graph.
		else if (*i != parent)
		return true;
	}
	return false;
}

// Returns true if the graph contains
// a cycle, else false.
bool Graph::isCyclic()
{
	
	// Mark all the vertices as not
	// visited and not part of recursion
	// stack
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper
	// function to detect cycle in different
	// DFS trees
	for (int u = 0; u < V; u++)
	{
		// Don't recur for u if
		// it is already visited
		if (!visited[u])
		if (isCyclicUtil(u, visited, -1))
			return true;
	}
	return false;
}

int main()
{
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.isCyclic()?
	cout << "Graph1 contains cycle\n":
	cout << "Graph1 doesn't contain cycle\n";

	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.isCyclic()?
	cout << "Graph2 contains cycle\n":
	cout << "Graph2 doesn't contain cycle\n";

	return 0;
}
