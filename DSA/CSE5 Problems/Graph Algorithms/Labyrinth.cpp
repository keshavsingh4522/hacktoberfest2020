#include<bits/stdc++.h> 
using namespace std;
bool checkboundary(int x, int y, int n, int m ,vector<vector<bool>> &vis,vector<vector<char>> &data)
{
    if(x >= 0 and x < n and y>= 0 and y < m and !vis[x][y] and (data[x][y] == '.' or data[x][y] == 'A' or data[x][y] == 'B'))
    return true;

    return false;
}
bool performBFS(int starti,int startj, int endi , int endj,int n,int m, vector<vector<bool>> &vis, vector<vector<char>> &data,vector<char>&path)
{   
    queue<pair<int,int>> temp;
   map<pair<int,int>, pair<int,int>> check;
    temp.push({starti,startj});
    while(!temp.empty())
    {
        int x = temp.front().first;
        int y = temp.front().second;
        temp.pop();

        if(x == endi and y == endj)
        {
           
            int currx = endi , curry = endj;
            while(currx != starti or curry != startj)
            {
                int newx = check[{currx,curry}].first,newy = check[{currx,curry}].second;
                if(newx + 1 == currx and newy == curry)
                path.push_back('D');
                else if(newx == currx and newy + 1 == curry)
                path.push_back('R');
                else if(newx -1 == currx and newy== curry)
                path.push_back('U');
                else if(newx == currx and newy -1 == curry)
                path.push_back('L');
                currx = newx , curry = newy;

            }
            reverse(path.begin(),path.end());
            return true;
        }

        if(checkboundary(x + 1, y, n, m,vis, data))
        {
            vis[x+1][y] = true;
            check[{x+1,y}] = {x,y};
            temp.push({x+1,y});
        }
          if(checkboundary(x , y + 1, n, m,vis, data))
        {
            vis[x][y + 1] = true;
            temp.push({x,y + 1});
            check[{x,y+1}] = {x,y};
        }
          if(checkboundary(x-1, y, n, m,vis, data))
        {
            vis[x-1][y] = true;
            temp.push({x-1,y});
            check[{x-1,y}] = {x,y};
        }
          if(checkboundary(x, y-1, n, m,vis, data))
        {
            vis[x][y-1] = true;
            temp.push({x,y-1});
            check[{x,y-1}] = {x,y};
        }
    }


    return false;
}
void solve()
{
    int  n, m,starti,startj,endi,endj;
    cin>>n>>m;
    vector<vector<char>> data(n,vector<char>(m,'.'));
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    vector<char> path;
    
    for(int i = 0; i < n; i++)
    for(int j = 0;j < m ;j++ )
    {
        cin>>data[i][j];
        if(data[i][j] == 'A')
        starti = i, startj = j;
        if(data[i][j] == 'B')
        endi = i, endj = j;
    }
    if(performBFS(starti, startj, endi, endj, n, m, vis, data,path)){
        cout<<"YES\n";
        cout<<int(path.size())<<"\n";
        for(char elem: path)
        cout<<elem<<"";
    }
    else
    cout<<"NO\n";

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
