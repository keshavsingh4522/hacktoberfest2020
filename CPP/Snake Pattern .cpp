//#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,row=5,col=5,arr[row*col],k=0;
    int mat[row][col]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{11,12,13,14,15},{11,12,13,14,15}};
    cout<<endl<<"Snake pattern: "<<endl;
    for(i=0;i<row;i++){
        if(i%2!=0){
            for(j=col-1;j>=0;j--){
                cout<<" "<<mat[i][j]<<" ";
            }
        }
        else{
            for(j=0;j<col;j++){
                cout<<" "<<mat[i][j]<<" ";
            }
        }
    }
    return 0;
}