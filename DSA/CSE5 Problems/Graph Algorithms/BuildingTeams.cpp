#include<bits/stdc++.h> 
using namespace std;
void solve()
{
 int n, m,x,y;
 bool possible = true;
 cin>>n>>m;
 vector<list<int>> edges(n+1);
 vector<int> colors(n+1,-1);


 while(m--){
     cin>>x>>y;
     edges[x].push_back(y);
     edges[y].push_back(x);
 }
 
for(int i = 1; i <= n; i++)
{
    if(colors[i] == -1)
    {
    colors[i] = 1;
    queue<int> temp;
    temp.push(i);
    while(!temp.empty())
    {
        int curr = temp.front();
        for(int elem : edges[curr])
        {
            if(colors[curr] == colors[elem])
                possible= false;
    
            if(colors[elem] == -1)
            {
                colors[curr] == 1?colors[elem] = 2:colors[elem] = 1;
                temp.push(elem);
            }
        }
        temp.pop();
        
    }
    
    }
}
if(!possible)
{
    cout<<"IMPOSSIBLE\n";
    return ;
}
 for(int i = 1; i <= n; i++)
 cout<<colors[i]<<" ";
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
