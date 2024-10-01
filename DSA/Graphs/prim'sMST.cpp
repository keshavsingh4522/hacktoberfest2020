#include<iostream>
#include <deque>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0); cin.tie(0);
 /* #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
         freopen("outpu.txt", "w", stdout);
    #endif */
     int N,m1;//m->number of edges and n-> number of vertices
     cin >> N >> m1;
     vector<pair<int,int> > adj[N]; 

     int a,b,wt;
     for(int i = 0; i<m1 ; i++){
          cin >> a >> b >> wt;
          adj[a].push_back(make_pair(b,wt));
          adj[b].push_back(make_pair(a,wt));
     }    
     
     int p[N];// at the end we are gonna contain only n-1 edges
    int k[N];  // this is distance array 
    bool m[N]; // this is visited array 
  
    for (int i = 0; i < N; i++) 
        k[i] = INT_MAX, m[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq; //min heap

    k[0] = 0;
    p[0] = -1; 
    pq.push({0, 0});
   
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        m[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (m[v] == false && weight < k[v]) {
                p[v] = u;
                 k[v] = weight; 
                pq.push({k[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << p[i] << " - " << i <<" \n"; 
     return 0;
}
