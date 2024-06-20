#include<bits/stdc++.h> 
using namespace std;
void performBFS(int curr, vector<list<int>> &edges, vector<bool> &vis,vector<set<int>> &components)
{
    vis[curr] = true;
    queue<int> temp ;
   set<int> component;
    component.insert(curr);
    temp.push(curr);
    while(!temp.empty())
    {
        int at = temp.front();
        temp.pop();
        for(int elem : edges[at])
        {
            if(!vis[elem])
            {
                vis[elem] = true;
                component.insert(elem);
                temp.push(elem);
            }
        }
    }
    components.push_back(component);
}
void solve()
{
    int n, m,x,y;
    cin>>n>>m;
    vector<list<int>> edges(n+1);
    vector<set<int>> comp;
    vector<bool> vis(n+1,false);
    while(m--)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        performBFS(i,edges, vis,comp);
    }
    if(comp.size() == 1)
        cout<<"0\n";
    else
     {
         cout<<int(comp.size())-1<<"\n";
         for(int i = 1; i < int(comp.size());i++)
         cout<<min(*comp[i-1].begin(),*comp[i].begin())<<" "<<max(*comp[i-1].begin(),*comp[i].begin())<<"\n";
     }
    
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
