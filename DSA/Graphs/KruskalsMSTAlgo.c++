#include<iostream>
#include <algorithm>

using namespace std;

class edge {
    public:
        int source, dest, wt;
};

void addEdge(edge g1[], int E) {
    for(int i=0; i<E; ++i) {
        int s, d, w;
        cin>>s>>d>>w;
        g1[i].source = s;
        g1[i].dest = d;
        g1[i].wt = w;
    }
}

int compare(edge e1, edge e2) {
    return e1.wt < e2.wt;
}

int findParent(int V, int *parent) {
    if(parent[V] == V ) return V;
    return findParent(parent[V], parent);
}

void KruskalsAlgo(edge g1[],int V,int E) {
    sort(g1, g1 + E, compare);

    edge *output = new edge[V-1];
    int *parent = new int[V];

    for(int i=0; i<V; ++i) parent[i] = i;

    int count = 0;
    for(int i=0; count!=V-1; ++i) {
        edge currentEdge = g1[i];

        int sourceParent = findParent(currentEdge.source, parent);
        int destinationParent = findParent(currentEdge.dest, parent);

        if(sourceParent != destinationParent) {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destinationParent;
        }
    }
    for(int i=0; i<V-1; i++) cout<<output[i].source<<" - "<<output[i].dest<<": "<<output[i].wt<<endl;
}

int main() {
    int V, E;
    cin>>V>>E;
    edge *g1 = new edge[E];
    cout<<"hmm: ";
   
    addEdge(g1, E);
    KruskalsAlgo(g1, V, E);

    return 0;
}