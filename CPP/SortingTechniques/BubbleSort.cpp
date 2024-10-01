#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int small_index = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[small_index])
                small_index = j;
        }
        swap(arr[i], arr[small_index]);
    }
}

int main(){
    int arr[5] = {5, 8, 1, 4, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<< " ";
    }
}
