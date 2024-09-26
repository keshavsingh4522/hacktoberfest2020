#include<iostream>
using namespace std;

int main() {

    int n, m;
    cout<<"Enter n and m: ";
    cin>>n>>m;

    int arr[n][m];

    cout<<"Enter matrix elements: "<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }

    int row_start=0, row_end=n-1;
    int column_start=0, column_end=m-1;

    while(row_start<=row_end && column_start<=column_end) {

        // for row start
        for(int i=column_start; i<=column_end; i++) {
            cout<<arr[row_start][i]<<" ";
        }
        row_start++;

        // for column end
        for(int i=row_start; i<=row_end; i++) {
            cout<<arr[i][column_end]<<" ";
        }
        column_end--;

        // for row end
        for(int i=column_end; i>=column_start; i--){
            cout<<arr[row_end][i]<<" ";
        }
        row_end--;

        // for column start
        for(int i=row_end; i>=row_start; i--){
            cout<<arr[i][column_start]<<" ";
        }
        column_start++;

    }

    return 0;
}