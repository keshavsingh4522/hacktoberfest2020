

// Shortest Path in an Undirected Graph with unit edge

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

void shortest_distance(vector<int> adj[],int N,int src){
    int dist[N];
    for(int i=0;i<N;i++) dist[i] = INT_MAX;

    queue<int> q;
    q.push(src);
    dist[src] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
    
        for(auto it:adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it] = 1 +dist[node];
                q.push(it);
            }            
        }
    }

    for(int i=0;i<N;i++) cout << dist[i] << " ";

}

// Shortest Path in a weighted DAG
/*
1. find toposort first
2. then just iterate over each element and find the shortest path
*/

// Djikstra's Algorithm

 // a pair is been put to priority queue when a lower distance is been observed
// set<pair<int,int>> can also be used so that similar values are not inserted in the queue basically


void djikstra(vector<pair<int,int>> adj[],int N,int src){ // pair is like (edge weight, connecting node)
    vector<int> dis(N,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dis[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        // may help to reduce rum time in very big cases
        if(dis[node]<dist) continue;
        for(auto ch:adj[node]){
            int nnode = ch.second;
            int distreq = ch.first;
            if(dis[nnode]>dist+distreq){
                dis[nnode] = dist+distreq;
                pq.push({dis[nnode],nnode});
            } 
        }
    }

}

// For negative edges
// Bellman Ford Algorithm for Directed Graph 
// if undirected converrt graph to directed 
// -ve cycle should be avoided and bellman ford algo detects it and can't be implmented for this course

// max N-1 relaxations are needed take the worst case longest path possible
// to detect negative cycle just do one more relaxation if dist array changes then there is a negative cycle

void bellman(vector<pair<int,int>> adj[],int N,int src){ // pair is like (node, edge weight)
    int inf = 1e9;
    vector<int> dist(N,inf);
    dist[src] = 0;
    for(int l=1;l<=N-1;l++){
        for(int i=0;i<N;i++){
            for(auto it:adj[i]){
                if(dist[i]+it.second<dist[it.first]){
                    dist[it.first] = dist[i]+it.second;
                }
            }
        }
    }

    bool isnegCycle = 0;
    for(int i=0;i<N;i++){
        for(auto it:adj[i]){
            if(dist[i]+it.second<dist[it.first]){
                isnegCycle = 1;
                cout << "Negative Cycle Exists";
                return;
            }
        }
    }

    for(int i=0;i<N;i++) cout << dist[i] << " ";
    // dist will be storing the shortest distances given constraints
}













