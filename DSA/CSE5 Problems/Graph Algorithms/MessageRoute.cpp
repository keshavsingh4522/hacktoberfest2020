#include<bits/stdc++.h> 
using namespace std;
void findShortestRoute(vector<list<int>> edges,int n, int m )
{
    vector<bool> vis(n+1, false);
    vector<int> parent(n+1, -1);
    queue<int> temp;
    temp.push(1);
    vis[1] = true;
    while(!temp.empty())
    {
        int curr = temp.front();
        temp.pop();
        if(curr == n)
        {
           
            vector<int> path;
            path.push_back(n);
            int curr = n;
            while(curr != 1)
            {
                path.push_back(parent[curr]);
                curr = parent[curr];
            }
            reverse(path.begin(),path.end());
            cout<<int(path.size())<<"\n";
            for(int elem : path)
            cout<<elem<<" ";
            return ;
        }
        for(int elem : edges[curr])
        {
            if(!vis[elem])
            {
               vis[elem]= true;
               parent[elem] = curr;
               temp.push(elem);
            }
        }
    }


cout<<"IMPOSSIBLE\n";
}
void solve()
{
    int n, m,x,y;
    cin>>n>>m;
    vector<list<int>> edges(n+1);
    while(m--)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    findShortestRoute(edges,n,m);
  
    
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
