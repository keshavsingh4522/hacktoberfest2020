/*
N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.


Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above


Example 2:

Input: n = 1
Output: [["Q"]]


Constraints:

1 <= n <= 9

https://leetcode.com/problems/n-queens/

*/


#include <bits/stdc++.h>
using namespace std;

//Print vector
void print(vector<vector<char> > v){
    for(auto i : v){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<char> > v,int row,int col){

    // check rows with passed col
    for(int i=0;i<row;i++){
        if(v[i][col] == 'Q'){
            return false;
        }
    }

    //Upper Left

    for(int i = row,j=col ; i>=0 && j>=0 ; i--,j--){
        if(v[i][j] == 'Q'){
            return false;
        }
    }

    //Upper right

    for(int i = row,j = col ; i>=0 && j<v.size() ; i--,j++){
        if(v[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

bool queen(vector<vector<char> > &v,int i){
    if(i == v.size()){
        print(v);
        return true;
    }


    for(int j = 0;j<v.size();j++){
        if(isSafe(v,i,j)){
            v[i][j] = 'Q';


            if(queen(v,i+1)){
                return true;
            }

            v[i][j] = '0';
        }
    }
    return false;
}


int main(){
   
    int n = 4;
    vector<vector<char> > v(n,vector<char>(n,'0'));
    queen(v,0);

    return 0;
}