#include <iostream>
#include <vector>
#include <queue>
#include <climits> // for INT_MAX

using namespace std;

// A pair to represent the node and its associated weight
typedef pair<int, int> pii;

// Dijkstra's algorithm function to find the shortest path
void dijkstra(int source, vector<vector<pii>> &adj, int n) {
    // Create a priority queue (min-heap)
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    // Vector to store the shortest distance from the source to each node
    vector<int> dist(n, INT_MAX);
    
    // Distance to the source is 0
    dist[source] = 0;
    
    // Push the source into the priority queue
    pq.push({0, source});
    
    while (!pq.empty()) {
        int curr_dist = pq.top().first; // Current distance from source
        int u = pq.top().second;        // Current node
        pq.pop();
        
        // If the popped node's distance is not the shortest, skip processing
        if (curr_dist > dist[u]) {
            continue;
        }
        
        // Iterate over all the adjacent nodes of u
        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;     // Neighboring node
            int weight = neighbor.second; // Edge weight
            
            // Relax the edge (u, v) if a shorter path is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    // Print the shortest distance to all nodes from the source
    cout << "Shortest distances from source node " << source << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Node " << i << ": Unreachable\n";
        } else {
            cout << "Node " << i << ": " << dist[i] << "\n";
        }
    }
}

int main() {
    int n, m; // Number of nodes and edges
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    
    // Adjacency list to store the graph (node, weight)
    vector<vector<pii>> adj(n);
    
    cout << "Enter the edges in the format (u v weight):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        
        // For an undirected graph, you need to add both directions
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }
    
    int source;
    cout << "Enter the source node: ";
    cin >> source;
    
    // Run Dijkstra's algorithm from the source node
    dijkstra(source, adj, n);
    
    return 0;
}
