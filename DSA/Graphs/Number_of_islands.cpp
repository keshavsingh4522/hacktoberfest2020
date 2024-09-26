#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the number of islands.
     void dfs(vector<vector<char>>& m, int x, int y, int& count){
         int r=m.size(),c=m[0].size(),ans=0;
        if(x<0||x>=r||y<0||y>=c|| m[x][y]=='0') return ; 
		//count++;                                      
	    m[x][y]='0';                              
        int dx[]={0,0,-1,1,1,-1,-1,1};
        int dy[]={1,-1,0,0,1,-1,1,-1};
        for(int i=0;i<8;i++){              
            int nx=x+dx[i];
            int ny=y+dy[i];
            dfs(m,nx,ny,count);
        }
            
    }
    int numIslands(vector<vector<char>>& m) {
        int r=m.size(),c=m[0].size(),ans=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(m[i][j]=='1'){             
                    int count=0;             
                    dfs(m,i,j,count);
                    ans++;                  
                }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends
