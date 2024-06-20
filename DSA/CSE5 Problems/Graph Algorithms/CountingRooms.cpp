#include<bits/stdc++.h> 
using namespace std;
bool checkboundary(int x, int y, int n, int m ,vector<vector<bool>> &vis)
{
    if(x >= 0 and x < n and y>= 0 and y < m and !vis[x][y])
    return true;

    return false;
}
void performBFS(int i, int j , int n, int m ,vector<vector<char>> &data, vector<vector<bool>> &vis)
{
    

    queue<pair<int,int>> temp;
    temp.push({i,j});
    vis[i][j] = true;
    while(!temp.empty())
    {
       int currx = temp.front().first;
       int curry = temp.front().second;
   
        temp.pop();
        if(checkboundary(currx + 1, curry, n, m, vis) and data[currx + 1][curry] == '.')
        {
            vis[currx + 1][curry] = true;
            temp.push({currx + 1, curry});
        }
        if(checkboundary(currx, curry + 1, n, m, vis) and data[currx][curry+ 1] == '.')
        {
            vis[currx][curry + 1] = true;
            temp.push({currx, curry + 1});
        }
        if(checkboundary(currx - 1, curry, n, m, vis) and data[currx - 1][curry] == '.')
        {
            vis[currx - 1][curry] = true;
            temp.push({currx - 1, curry});
        }
        if(checkboundary(currx, curry-1, n, m, vis) and data[currx][curry - 1] == '.')
        {
            vis[currx][curry-1] = true;
            temp.push({currx, curry-1});
        }
       
    }
    
}
void solve()
{
    int  n, m,ans = 0;
    cin>>n>>m;
    vector<vector<char>> data(n,vector<char>(m,'.'));
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    
    for(int i = 0; i < n; i++)
    for(int j = 0;j < m ;j++ )
    cin>>data[i][j];



    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
    {
        if(!vis[i][j] and data[i][j] == '.')
        {
            ans += 1;
            performBFS(i, j, n, m, data, vis);
        }
    }
    cout<<ans<<"\n";


}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
