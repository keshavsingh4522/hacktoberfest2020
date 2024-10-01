#include <bits/stdc++.h>
using namespace std;

void printBFS(int** arr,int n,int sv,bool* visited){
  if(n==0){
      return;
  }
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
while(!q.empty()){
    int s = q.front();
    q.pop();
    cout<<s<<" ";
    for(int i=0;i<n;i++){
        if(i == s){
            continue;
        }
        if(arr[s][i] == 1){
            if(visited[i]){
                continue;
            }
            q.push(i);
            visited[i] = true;
        }
    }
}
    
    
}

void BFS(int** edges,int n){


bool* visited = new bool[n];
for(int i=0;i<n;i++){
    visited[i] = false;
}
  for(int i=0;i<n;i++){
      if(!visited[i]){
          printBFS(edges,n,i,visited);
      }
  }

delete [] visited;
}

int main(){
int n,e;
cin>>n>>e;
int** edges = new int*[n];
for(int i=0;i<n;i++){
    edges[i] = new int[n];
    for(int j=0;j<n;j++){
        edges[i][j] = 0;
    }
}
for(int i=0;i<e;i++){
    int f,s;
    cin>>f>>s;
    edges[f][s] = 1;
    edges[s][f] = 1;
}


BFS(edges,n);
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete[] edges;
}