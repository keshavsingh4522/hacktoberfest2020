#include<bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    int arr[n+1];
    arr[0]=0;
    for(int i=1; i<n+1; i++) {
        cin>>arr[i];
        sort(arr, arr+i+1);
        if(i==1) {
            cout<<arr[i]<<" ";
        }
        else if(i%2==0) {
            cout<<(arr[i/2]+arr[(i/2)+1])/2<<" ";
        }
        else {
            cout<<arr[i/2+1]<<" ";
        }
    }
    return 0;
}
