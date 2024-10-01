#include <bits/stdc++.h>

using namespace std;

    class DSU{
private:
    vector<int> parent,size;

public:
    DSU(int n){
        for(int i = 0;i <= n;i++) {
            parent.push_back(i);
            size.push_back(1);
        }
    }

public:
    int findPar(int node) {
        if(parent[node] == node) {
            return node;
        }
        // Path compression --> log(n)
        // Path compression and size --> O(4 x alpha) 
        return parent[node] = findPar(parent[node]);
    }

public:
    void Union(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu == pv){
            return;
        }

        if(size[pv] < size[pu]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
}

int main() {
    int n = 10;
    DSU dsu(n);
}
