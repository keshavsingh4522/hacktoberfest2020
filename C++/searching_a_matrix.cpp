#include<iostream>
using namespace std;

int main() {
    int n, m , x;

    cout<<"Enter array size: ";
    cin>>n>>m;

    int arr[n][m];

    cout<<"Enter array elements: "<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }

    cout<<"Enter element to serach: ";
    cin>>x;

    for(int i=0; i<n; i++)  {
        for(int j=0; j<m; j++) {
            if(arr[i][j] == x) {
                cout<<"Element found"<<endl;
                cout<<"Index: "<<i<<" "<<j;
                return 0;
            }               
        }
    }

    cout<<"Element not found!"<<endl;

    return 0;
}