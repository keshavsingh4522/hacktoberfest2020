
#include<bits/stdc++.h>
using namespace std;
int totalpath=0;
bool isitsafe( int i , int j ,int n ,vector<vector<bool>>& visited){
return i>=0 and i>=0 and i<n and j<n and visited[i][j]==false;}



void helper(int i , int j, int n,vector<vector<int>>&grid,vector<vector<bool>>&visited){
if(i==n-1 and j==n-1){
    totalpath++;
    return ;
}
if( !isitsafe( i,j,n,visited)){
    return ;
}
visited[i][j]=true;
if(i+1<n and grid[i+1][j]==0){//down
    helper(i+1,j,n,grid,visited);
}
if(i-1>=0 and grid[i-1][j]==0){//up
    helper(i-1,j,n,grid,visited);
}
if(j+1<n and grid[i][j+1]==0){
    helper(i,j+1,n,grid,visited);
}
if( j-1>=0 and grid[i][j-1]==0){
    helper(i,j-1,n,grid,visited);
}

visited[i][j]=false;
return ;



}





int  rat(vector<vector<int>>&grid){
    int n =grid.size();
    vector<vector<bool>>visited(n,vector<bool>(n,false));
    helper(0,0,n,grid,visited);
    return totalpath;
}
 int main (){
     int n;
     cin>>n;
     vector<vector<int>>grid(n,vector<int>(n,0));
     for(int i=0 ;i<n;i++){
      for(int j=0 ;j<n;j++){
        cin>>grid[i][j];
     }
     }
     cout<<rat(grid);
 }
