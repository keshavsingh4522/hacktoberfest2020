#include<iostream>
using namespace std;

int main() {

    int n, m;
    cout<<"Enter n(rows) and m(columns): ";
    cin>>n>>m;

    int arr[n][m];

    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        cout<<endl;
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
    }


    return 0;
}
