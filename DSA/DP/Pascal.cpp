//Given an integer numRows, return the first numRows of Pascal's triangle.
//In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<vector<int>> generatePascal(int numRows) {
vector<vector<int>>result;
if(numRows==0)return result;
vector<int>t;
t.push_back(1);
result.push_back(t);
if(numRows==1)return result;
vector<int>tt;
tt.push_back(1);
tt.push_back(1);
result.push_back(tt);
if(numRows==2)return result;
for(int i=2;i<numRows;i++){
    vector<int>temp;
    temp.push_back(1);
    for(int j=1;j<i;j++){
        temp.push_back(result[i-1][j-1]+result[i-1][j]);
        //cout<<result[i-1][j-1]+result[i-1][j]<<" ";
    }
    temp.push_back(1);
    result.push_back(temp);
}

return result;
}



int main(){
    vector<vector<int>>nums = generatePascal(3);
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[i].size();j++){
            cout<<nums[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



