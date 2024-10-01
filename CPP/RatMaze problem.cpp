//RAT MAZE PROBLEM IN C++
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void ratHelper(int maze[][20],int sol[12][12],int n,int row, int col){
    //when destination is reached (last cell)
    if (row==n-1 && col==n-1){
        //since it didnt enter the backtracking functions, set the value of sol here
        sol[row][col]=1;
        //print one sol
        for(int i=0; i<n; i++)
        	for(int j=0; j<n; j++) cout<<sol[i][j]<<" ";
        cout<<endl;
        sol[row][col]=0;
        return;
    }
    //not traversing one cell twice or blocked cell or out of boundary cells
	if(row>=n || row<0 || col>=n || col<0 || maze[row][col] ==0 || sol[row][col]==1){ 
        //cout<<maze[row][col];
		return;
	}
    //backtracking
        sol[row][col]=1; //set the current cell as 1 since already visited
        ratHelper(maze,sol,n,row,col-1); //left
        ratHelper(maze,sol,n,row,col+1); //right
    	ratHelper(maze,sol,n,row-1,col); //up
    	ratHelper(maze,sol,n,row+1,col); //down
        sol[row][col]=0; //after the individual recursive calls complete they end here and reseting the cells starts
    
}


void ratInAMaze(int maze[][20], int n){

    int sol[12][12];
	memset(sol,0,12*12*sizeof(int));
    ratHelper(maze,sol,n,0,0);

}


int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
    for(int j = 0; j < n; j++){
            cin >> maze[i][j];
        }       
  }
  ratInAMaze(maze, n);
}